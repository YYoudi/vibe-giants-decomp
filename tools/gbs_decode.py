#!/usr/bin/env python3
# Standalone GBS decoder — faithful port of Amazed's blender-giants-plugin/gbs_plugin/shared.py
# (clean-room RE, rule: use existing RE resources). Decodes a Giants .gbs model into an OBJ +
# a JSON summary (verts/faces/materials). No Blender dependency.
import struct, sys, json, os

GBS_VERSION = 0xaa0100be
F_NORMALS, F_UVS, F_RGBS, F_CALCN = 0x1, 0x2, 0x4, 0x8

class R:
    def __init__(self, d): self.d=d; self.o=0
    def u32(self):
        v=struct.unpack_from('<I',self.d,self.o)[0]; self.o+=4; return v
    def u16(self):
        v=struct.unpack_from('<H',self.d,self.o)[0]; self.o+=2; return v
    def u8(self):
        v=self.d[self.o]; self.o+=1; return v
    def f32(self):
        v=struct.unpack_from('<f',self.d,self.o)[0]; self.o+=4; return v
    def s(self, n):
        v=self.d[self.o:self.o+n].split(b'\x00')[0].decode('latin1'); self.o+=n; return v

def decode(path):
    r = R(open(path,'rb').read())
    magic = r.u32()
    if magic != GBS_VERSION:
        print(f'bad magic {magic:#x}'); return None
    flags = r.u32()
    nverts_unique = r.u32()
    verts = [(r.f32(), r.f32(), r.f32()) for _ in range(nverts_unique)]
    info = dict(magic=hex(magic), flags=flags,
                flag_normals=bool(flags&F_NORMALS), flag_uvs=bool(flags&F_UVS), flag_rgbs=bool(flags&F_RGBS),
                num_unique_vertices=nverts_unique)
    if flags & F_NORMALS:
        nndefs = r.u32(); num_normals = r.u32()
        info['num_normals']=num_normals
        normals = [r.u16() for _ in range(num_normals)]
    nverts = r.u32()  # indexed vertex count
    idx_vert = [r.u16() for _ in range(nverts)]
    if flags & F_NORMALS:
        idx_norm = [r.u16() for _ in range(nverts)]
    if flags & F_UVS:
        uvs = [(r.f32(), -r.f32()) for _ in range(nverts)]  # v flipped (canonical reader does *-1)
    if flags & F_RGBS:
        rgbs = [((r.u8(), r.u8(), r.u8())) for _ in range(nverts)]
    info['nverts_indexed']=nverts
    # max objects
    nmobjs = r.u32()
    maxobjs=[]
    for _ in range(nmobjs):
        vstart,vcnt,nstart,ncnt,noffset = (r.u32() for _ in range(5))
        maxobjs.append(dict(vstart=vstart,vcount=vcnt,nstart=nstart,ncount=ncnt,noffset=noffset))
    # sub objects (the triangle groups + material names)
    nsobjs = r.u32()
    print(f'[dbg] nmobjs={nmobjs} nsobjs={nsobjs} nverts_idx={nverts} pos={r.o}', file=sys.stderr)
    subobjs=[]; total_tris=0
    for si in range(nsobjs):
        name = r.s(32)
        maxobjindex = r.u32()
        totaltris = r.u32()
        ntris = r.u32()
        print(f'[dbg] subobj{si}: name={name!r} maxobj={maxobjindex} totaltris={totaltris} ntris={ntris} pos={r.o}', file=sys.stderr)
        tridata = [r.u16() for _ in range(ntris)]
        vertref_start = r.u32(); vertref_count = r.u32()
        texname = r.s(32) if (flags & F_UVS) else ''
        bumptex = r.s(32) if (flags & F_UVS) else ''
        falloff = r.f32()
        blend = r.f32() if (flags & F_RGBS) else 0.0
        sflags = r.u32(); emissive=r.u32(); ambient=r.u32(); diffuse=r.u32(); specular=r.u32(); power=r.f32()
        subobjs.append(dict(name=name, maxobjindex=maxobjindex, totaltris=totaltris, ntris=ntris,
                            tridata=tridata, texname=texname, bumptex=bumptex, falloff=falloff, blend=blend,
                            flags=sflags, emissive=emissive, ambient=ambient, diffuse=diffuse,
                            specular=specular, power=power))
        subobjs.append(dict(name=name, maxobjindex=maxobjindex, totaltris=totaltris,
                            ntris=ntris, tridata=tridata))
        total_tris += totaltris
    info['num_maxobjs']=nmobjs; info['num_subobjs']=nsobjs; info['total_tris']=total_tris
    info['maxobjs']=maxobjs
    info['subobj_summary']=[{k:v for k,v in s.items() if k!='tridata'} for s in subobjs]
    info['subobj_names']=[s['name'] for s in subobjs]
    info['vertex_bbox']=bbox(verts)
    # emit OBJ (unique verts + per-subobj tris). tridata encodes tri indices (3 shorts each, with a stride)
    out = path+'.obj'
    with open(out,'w') as f:
        for x,y,z in verts: f.write(f'v {x} {y} {z}\n')
        if flags & F_UVS:
            for u,v in uvs: f.write(f'vt {u} {v}\n')
        for s in subobjs:
            f.write(f'o {s["name"]}\n')
            # Strip-decode tridata per evaluate_tridata (canonical reader).
            td = s['tridata'][:]; tri_idx = -1; count = 0
            for _ in range(s['totaltris']):
                if count == 0:
                    count = td[0]
                    if count == 0: break
                    tri_idx = 0
                v1 = td[tri_idx+1]; v2 = td[tri_idx+2]; v3 = td[tri_idx+3]
                tri_idx += 3; count -= 1
                if count < 0: count = 0xffff
                if count == 0:
                    td = td[td[0]*3+1:]; tri_idx = -1
                f.write(f'f {v1+1} {v2+1} {v3+1}\n')
    info['obj']=out
    return info

def bbox(verts):
    xs=[v[0] for v in verts]; ys=[v[1] for v in verts]; zs=[v[2] for v in verts]
    return dict(x=(min(xs),max(xs)), y=(min(ys),max(ys)), z=(min(zs),max(zs)))

if __name__=='__main__':
    p = sys.argv[1] if len(sys.argv)>1 else 'extracted/logo3d/Giants_logo_3D.gbs'
    info = decode(p)
    print(json.dumps({k:v for k,v in info.items() if k not in ('maxobjs',)}, indent=2, default=str)[:3000])
    print('--- maxobjs ---')
    for m in info['maxobjs']: print(' ', m)
    print('--- subobj names ---')
    for n in info['subobj_names']: print(' ', repr(n))
