#!/usr/bin/env python3
"""
Extract & demangle function/global symbols from the Giants PS2 prototype ELF
(SLUS_201.78) so they can be used as a names/types dictionary for the PC
decompilation project (G:\\GiantsRE).

Reproducible: re-extracts the ELF from the ISO with 7z if missing.

GNU old-style (pre-Itanium, GCC 2.95) mangling decoder, e.g.:
    ai_do_update_goal__FUiP6OBJECTP3P3Dff
    ->  ai_do_update_goal(unsigned int, OBJECT*, P3D*, P3D*, float, float)

Outputs:
    ps2_symbols/SLUS_201.78.symbols.csv   full table
    ps2_symbols/SLUS_201.78.functions.txt demangled one per line
"""
import csv, os, re, subprocess, sys, collections

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)
ISO = os.path.join(REPO, "RESSOURCES_FOR_AI", "sent_by_Amazed",
                   "PS2 Port Sep 19, 2001 prototype- Giants Citizen Kabuto Review Code 09.01.iso")
ELF_NAME = "SLUS_201.78"
ELF = os.path.join(HERE, ELF_NAME)
SEVENZIP = r"C:\Program Files\7-Zip\7z.exe"

def ensure_elf():
    if os.path.exists(ELF):
        return
    if not os.path.exists(ISO):
        sys.exit(f"ISO not found: {ISO}")
    print(f"[*] extracting {ELF_NAME} from ISO ...")
    subprocess.check_call([SEVENZIP, "e", ISO, "-o"+HERE, ELF_NAME, "-y"],
                          stdout=subprocess.DEVNULL)
    assert os.path.exists(ELF), "ELF extraction failed"

# --- old-GNU demangler -------------------------------------------------------
def _prim(code):
    return {
        'v':'void','c':'char','b':'bool','s':'short','i':'int','l':'long',
        'f':'float','d':'double','r':'long double',
        'x':'long long','y':'unsigned long long',
        'Ui':'unsigned int','Ul':'unsigned long','Us':'unsigned short',
        'Uc':'unsigned char','Ux':'unsigned long long',
    }.get(code)

class Dem:
    def __init__(self, s):
        self.s = s; self.i = 0
    def peek(self): return self.s[self.i] if self.i < len(self.s) else ''
    def take_named(self):
        m = re.match(r'\d+', self.s[self.i:])
        if not m: return None
        n = int(m.group(0)); self.i += len(m.group(0))
        name = self.s[self.i:self.i+n]; self.i += n
        return name
    def type(self, depth=0):
        ch = self.peek()
        # const/volatile qualifiers
        if ch == 'C': self.i+=1; return 'const '+self.type(depth)
        if ch == 'U':
            # U could be 'unsigned X' OR start of 'Ui','Ul'... only if next is a prim letter
            two = self.s[self.i:self.i+2]
            if two in ('Ui','Ul','Us','Uc','Ux'):
                self.i+=2; return _prim(two)
            # else treat as named (rare)
        if ch == 'P': self.i+=1; return self.type(depth)+'*'
        if ch == 'R': self.i+=1; return self.type(depth)+'&'
        if ch == 'A':  # array A<n>_
            self.i+=1
            m=re.match(r'\d+', self.s[self.i:]); sz=''
            if m: sz=m.group(0); self.i+=len(sz)
            if self.peek()=='_': self.i+=1
            return self.type(depth)+f'[{sz}]'
        if ch == 'T':  # back-reference T0,T1...
            self.i+=1
            m=re.match(r'\d+', self.s[self.i:]); self.i+=len(m.group(0))
            return '/*same*/'
        # named type: <len><name>
        nm = self.take_named()
        if nm is not None: return nm
        # primitive single-letter
        self.i+=1
        return _prim(ch) or '?'+ch

def demangle(mangled):
    # function: NAME__F<args>   member: NAME__FR<i>C<args> etc.  global var: NAME
    if '__F' in mangled:
        name, rest = mangled.split('__F', 1)
        args = rest[0:] if not rest.startswith('R') else rest  # drop leading F
        d = Dem(rest)
        params=[]
        if d.peek()=='':
            params=['void']
        else:
            while d.i < len(d.s):
                p=d.type()
                if p is None: break
                params.append(p)
                if d.peek()=='' : break
        # clean
        params=[p for p in params if p and p!='void'] or ['void']
        return f"{name}({', '.join(params)})"
    if '__FR' in mangled or '__FC' in mangled:
        name, rest = mangled.split('__',1)
        return f"{name}({rest}) /*old-style member*/"
    return mangled

def main():
    ensure_elf()
    from elftools.elf.elffile import ELFFile
    with open(ELF,'rb') as f:
        e = ELFFile(f)
        st = e.get_section_by_name('.symtab')
        rows=[]
        for s in st.iter_symbols():
            t = s['st_info']['type']
            if not s.name: continue
            kind = {'STT_FUNC':'FUNC','STT_OBJECT':'OBJ','STT_NOTYPE':'NOTYPE',
                    'STT_SECTION':'SEC'}.get(str(t), str(t))
            rows.append({
                'addr': f"0x{s['st_value']:08x}",
                'size': s['st_size'],
                'kind': kind,
                'bind': str(s['st_info']['bind']),
                'section': s['st_shndx'],
                'mangled': s.name,
                'demangled': demangle(s.name),
            })
    funcs = [r for r in rows if r['kind']=='FUNC' and r['size']>0]
    csvp = os.path.join(HERE, "SLUS_201.78.symbols.csv")
    with open(csvp,'w',newline='',encoding='utf-8') as f:
        w=csv.DictWriter(f, fieldnames=['addr','size','kind','bind','section','demangled','mangled'])
        w.writeheader(); w.writerows(sorted(rows, key=lambda r:r['addr']))
    with open(os.path.join(HERE,"SLUS_201.78.functions.txt"),'w',encoding='utf-8') as f:
        for r in sorted(funcs,key=lambda r:r['addr']):
            f.write(f"{r['addr']}\t{r['size']:6d}\t{r['demangled']}\n")
    print(f"[+] {len(rows)} symbols, {len(funcs)} named functions")
    print(f"[+] wrote {csvp}")
    print(f"[+] wrote ...functions.txt")

if __name__=='__main__':
    main()
