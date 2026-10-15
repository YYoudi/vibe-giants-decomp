/* giants_types.h — structs RE connues (GOG 1.449 PC, x86 32-bit, MSVC)
 *
 * Provenance par champ : voir docs/formats/OBJECT_LAYOUT.md (observed /
 * derived / inferred). Champs inconnus = _pad_<offset> — à remplacer au fil
 * des validations runtime. NE JAMAIS deviner un _pad.
 *
 * Alignement : x86 32-bit, packed par défaut MSVC (aucun membre > 4 octets
 * ne force un alignement supérieur dans les structs ci-dessous).
 */
#ifndef GIANTS_TYPES_H
#define GIANTS_TYPES_H

#include <stdint.h>

typedef uint32_t u32; typedef int32_t s32;
typedef uint16_t u16; typedef int16_t s16;
typedef uint8_t u8;   typedef int8_t s8;
typedef float f32;

/* ===== OBJECT (embarqué à acteur+0x0C dans les records FLK 0x874) =====
 * 135 champs minés (ps2_symbols/OBJECT_LAYOUT.csv + docs/formats/object_layout_pc.csv).
 * Ne sont déclarés que les champs à sémantique établie ; le reste est _pad. */
typedef struct OBJECT {
    u32     _pad_000;      /* +0x00 non établi (next? spec?) */
    u32     type_id;       /* +0x04 observed — 0x65/0x66 = actors flick */
    u32     class_ptr;     /* +0x08 inferred — mass/class (25f PS2) */
    u32     team_link;     /* +0x0C inferred — army_count_rpman (12f) */
    void*   anim;          /* +0x10 observed — ANM_Anim* courant */
    u32     _pad_014[49];  /* +0x14..0xD7 — voir CSV champ par champ */
    u32     flags;         /* +0xD8 observed — b0x20 flick-anim, b0x40 loc-gate, b0x8000 freed */
    f32     coll_radius;   /* +0xE0 derived — collide/vu0/TreeBend */
    u32     _pad_0e4[7];   /* +0xE4..0xFC */
    u32     animate_state; /* +0x100 derived — object_animate_process */
    f32     vel[3];        /* +0x108..0x110 derived — vélocité courante (x,y,z) */
    f32     vel_w;         /* +0x114 — 4e composant vel (w/accum — rôle exact ouvert) */
    f32     prev_vel[3];   /* +0x118..0x120 — vel PRÉCÉDENTE (shift 0x118<-0x108 vu dans obj_velocity_commit) */
    f32     prev_vel_w;    /* +0x124 */
    u32     _pad_128[2];   /* +0x128..0x12C */
    f32     loc_accum[4];  /* +0x130..0x13F derived — apply_location + TargetCenter */
    u32     _pad_140[3];   /* +0x140..0x14B */
    f32     waypoint[4];   /* +0x150..0x15F inferred(18f) — lift/buoy/collgrid/rockgen */
    u32     _pad_160[2];   /* +0x160..0x167 */
    u32     _pad_168;
    u32     anim_selector; /* +0x16C derived(18f) — *_select_run_anim */
    u32     _pad_170[3];   /* +0x170..0x17B */
    u32     actor_spec;    /* +0x180 derived(47f) — bloc classe/tir (ptr ou inline : TROU) */
    u32     _pad_184[6];   /* +0x184..0x19B */
    u32     ai_state_b;    /* +0x18C derived(15f) — ripper_switch_to_normal_ai */
    u32     _pad_190[7];   /* +0x190..0x1A7 */
    void*   orders_head;   /* +0x1A8 derived(102f) — liste d'ordres armée */
    u32     _pad_1ac[12];  /* +0x1AC..0x1DB */
    u32     state;         /* +0x1E0 observed — 0x3D = mode acteur-cinématique */
    u32     _pad_1e4[42];  /* +0x1E4..0x28B */
    u32     death_state;   /* +0x28C inferred(23f) — rpman_handle_death */
    u32     _pad_290[18];  /* +0x290..0x2D7 */
    void*   alloc_data[3]; /* +0x2D8..0x2E0 derived — object_free_all_allocated_data */
    u32     _pad_2e4[2];   /* +0x2E4..0x2EB */
    u32     shrinker;      /* +0x2EC inferred(13f) */
    f32     energy;        /* +0x2F0 derived(11f) — EnergyIncrease */
    u32     _pad_2f4[87];  /* +0x2F4..0x463 */
    u32     shadow;        /* +0x464 derived(3f) — RenderShadow */
} OBJECT;                  /* taille totale : non bornée (voir doc) */

/* ===== FLK_Actor (0x874) — acteur de cinématique ===== */
typedef struct FLK_Actor {
    void*   director;      /* +0x00 — ANM_Anim* du director (FLK_ActorAdd) */
    char*   name;          /* +0x04 */
    u32     enabled;       /* +0x08 */
    OBJECT  object;        /* +0x0C — embarquée */
    u32     _pad_after_obj[0x1B9]; /* jusqu'à +0x7DF */
    f32     offset_mat[12];/* +0x7E0 — matrice offset (FLK_ActorOffsetEval) */
    u32     _pad_810[19];
    f32     scale_lerp;    /* +0x860 */
    u32     _pad_864[2];
    u32     in_use;        /* +0x870 — 1 = slot occupé */
    u32     _pad_874[1];
} FLK_Actor;               /* 0x874 */

/* ===== FLK_Flick (dwords indexés — flick_file_load @ 0x443480) =====
 * indices en dwords depuis la base du struct (flick[0xNN]) */
#define FLK_MAP          0x00   /* map handle */
#define FLK_NAME         0x01   /* char[0x80] */
#define FLK_CURSOR       0x22   /* curseur VM persistant (+0x88) */
#define FLK_NUMANIMS     0x24   /* (+0x90) */
#define FLK_NUMACTORS    0x25   /* (+0x94) */
#define FLK_ANIMS        0x27   /* (+0x9C) table 0xC/entrée */
#define FLK_ACTORS       0x28   /* (+0xA0) table 0x874/entrée */
#define FLK_ATTACHES     0x29   /* (+0xA4) table 0x310/entrée */
#define FLK_TIME_SCALE   0x34   /* (+0xD0) f32 */
#define FLK_CLOCK        0x2C   /* (+0xB0) horloge flick (f32, avancée dt) */
#define FLK_CAMOBJ       0x2D   /* (+0xB4) OBJECT caméra lié op 4 */
#define FLK_DT           0x2B   /* (+0xAC) dt propre flick */

/* ===== ANM_Node inline (director FLK, records [ptr][size][0]) =====
 * cf. docs/formats/ANM_IMAGE.md — validé runtime (nam_entry_ctor @ 0x53D700) */
typedef struct ANM_Node {
    u32     _pad_000;      /* +0x00 mis à 0 par le ctor */
    u16     cls;           /* +0x04 1 → trio blend +0xF8 existe */
    u16     track_type;    /* +0x06 0=none 1=+0x9C 2/3=+0x98/9C/A0 */
    u32     name_handle;   /* +0x08 {u16,u16} — table NAM */
    void*   group;         /* +0x0C ptr fixé ctor (0x46B88 partagé) */
    void*   parent;        /* +0x10 ptr fixé ctor */
    void*   _pad_014;
    void*   callback;      /* +0x18 (out, affine, node, anim) */
    u32     _pad_01c[17];  /* +0x1C..+0x5F (matrice cache +0x24) */
    f32     pos[3];        /* +0x6C */
    f32     rot_euler[3];  /* +0x78 — NIÉES au chargement par nam_entry_ctor */
    f32     scale[3];      /* +0x84 */
    f32     one;           /* +0x90 = 1.0 */
    u32     const_10;      /* +0x94 = 0x10 */
    void*   keys_pos;      /* +0x98 ANM_Keys* */
    void*   keys_rot;      /* +0x9C */
    void*   keys_scale;    /* +0xA0 */
} ANM_Node;                /* ≥ 0xB0, taille variable (trio blend +0xF8) */

/* ===== ANM_Keys ===== */
typedef struct ANM_Keys {
    void*   _pad_000;
    u32     _pad_004;
    u32     count;         /* +0x08 */
    void*   keys[];        /* +0x0C — chaque clé ptr relogé */
} ANM_Keys;

/* Clé de position : {f32 x,y,z ; u32 tick@+0xC}, stride 0x3C.
 * Clé de rotation : {u32,u32, quat ×3, tick@+0x38} — NON DÉCODÉ (trou). */

#endif /* GIANTS_TYPES_H */
