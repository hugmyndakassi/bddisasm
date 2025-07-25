/*
 * Copyright (c) 2020 Bitdefender
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef BDX86_TABLEDEFS_H
#define BDX86_TABLEDEFS_H

#include "../inc/bddisasm_types.h"

//
// Types of tables.
//
typedef enum _ND_ILUT_TYPE
{
    /// Table contains one entry that contains an index inside the IDB.
    ND_ILUT_INSTRUCTION = 0,

    /// Table contains 256 entries. Next entry is selected using an opcode.
    ND_ILUT_OPCODE,

    /// Table contains 256 entries. Next entry is selected using an opcode, but the opcode follows the instruction as 
    /// the last byte.
    ND_ILUT_OPCODE_LAST,

    /// Table contains 8 entries. Next entry is selected using modrm.reg.
    ND_ILUT_MODRM_REG,

    /// Table contains 2 entries. Next entry is selected using modrm.mod (0 - mem, 1 - reg).
    ND_ILUT_MODRM_MOD,

    /// Table contains 8 entries. Next entry is selected using modrm.rm.
    ND_ILUT_MODRM_RM,

    /// Table contains 4 entries. Next entry is 0 (no prefix), 1 (0x66), 2 (0xF3), 3 (0xF2).
    ND_ILUT_MAN_PREFIX,

    /// Table contains 4 entries. Next entry is 1 (16 bit mode), 2 (32 bit mode), 3 (64 bit mode) or 0 (default).
    ND_ILUT_MODE,

    /// Default addressing mode is used to transition.
    ND_ILUT_ASIZE,

    /// Table contains 4 entries. Next entry is 1 (16 bit size), 2 (32 bit size), 3 (64 bit size) or 0 (default).
    ND_ILUT_DSIZE,

    /// Table contains 10 entries. Next entry is 0 (no prefix), 1 (rex), 2 (rex.w), etc.
    ND_ILUT_AUXILIARY,

    /// Preferred vendor is used to transition. Default is entry 0. Otherwise, preferred vendor selects an alternate 
    /// entry.
    ND_ILUT_VENDOR,

    /// Some instructions are mapped onto wide NOP space. They will be decoded only if the associated feature is set 
    /// during decoding.
    ND_ILUT_FEATURE,

    /// Table contains 32 entries. Next entry is vex/xop/evex.mmmmm.
    ND_ILUT_EX_M,

    /// Table contains 4 entries. Next entry is vex/xop/evex.pp.
    ND_ILUT_EX_PP,

    /// Table contains 4 entries. Next entry is vex/xop.l or evex.l'l.
    ND_ILUT_EX_L,

    /// Table contains 2 entries. Next entry is vex/xop/evex.w.
    ND_ILUT_EX_W,

    /// Table contains 2 entries. Next entry is vex/xop/evex.w. If not in 64 bit, next entry is 0.
    ND_ILUT_EX_WI,

    /// Table contains 2 entries. Next entry is evex.ND.
    ND_ILUT_EX_ND,

    /// Table contains 2 entries. Next entry is evex.NF. 
    ND_ILUT_EX_NF,

    /// Table contains 16 entries. Next entry is evex.SC.
    ND_ILUT_EX_SC,

    /// Table contains 64 entries. Next entry is evex.l << 4 | evex.p << 2 | evex.nd << 1 | evex.nf.
    ND_ILUT_EX_LPDF,

    /// Not valid if 64-bit mode.
    ND_ILUT_FLT_NO64,

    /// Not valid outside 64-bit mode.
    ND_ILUT_FLT_NO1632,

    /// Not valid with RIP-relative addressing.
    ND_ILUT_FLT_NORIPREL,

    /// Not valid with 16-bit addressing.
    ND_ILUT_FLT_NOA16,

    /// Not valid with 0x66 prefix.
    ND_ILUT_FLT_NO66,

    /// Not valid with 0x67 prefix.
    ND_ILUT_FLT_NO67,

    /// Not valid with REP prefix.
    ND_ILUT_FLT_NOREP,

    /// Not valid with REX2 prefix.
    ND_ILUT_FLT_NOREX2,

    /// Not valid with L'L == 0.
    ND_ILUT_FLT_NOL0,

    /// Not valid with VVVV != 0.
    ND_ILUT_FLT_NOV,

    /// Not valid with V' != 0.
    ND_ILUT_FLT_NOVP,

    /// Not valid with VVVV != 0 or VP != 0.
    ND_ILUT_FLT_NOVVP,

    /// GPR encoded in R must be less than 16 outside APX.
    ND_ILUT_FLT_RRLT16,

    /// GPR encoded in V must be less than 16 outside APX.
    ND_ILUT_FLT_RVLT16,

    /// Segment register encoded in R must be less than 6.
    ND_ILUT_FLT_SRIN012345,

    /// Segment register encoded in R must be less than 6 and not 1 (CS).
    ND_ILUT_FLT_SRIN02345,

    /// Bound register encoded in R must be less than 4.
    ND_ILUT_FLT_BRLT4,

    /// Bound register encoded in M must be less than 4.
    ND_ILUT_FLT_BMLT4,

    /// Control register encoded in R must be 0, 2, 3, 4 or 8.
    ND_ILUT_FLT_CRIN02348,

    /// Debug register encoded in R must be less than 8.
    ND_ILUT_FLT_DRLT8,

    /// Test register encoded in R must be less than 8.
    ND_ILUT_FLT_QRLT8,

    /// Mask register encoded in R must be less than 8.
    ND_ILUT_FLT_KRLT8,

    /// Mask register encoded in V must be less than 8.
    ND_ILUT_FLT_KVLT8,

    /// Tile register encoded in R must be less than 8.
    ND_ILUT_FLT_TRLT8,

    /// Tile register encoded in M must be less than 8.
    ND_ILUT_FLT_TMLT8,

    /// Tile register encoded in V must be less than 8.
    ND_ILUT_FLT_TVLT8,

    /// VSIB index register, source & destination must be distinct.
    ND_ILUT_FLT_VXNEVR_VXNEVV_VRNEVV,

    /// VSIB index register & destination must be distinct.
    ND_ILUT_FLT_VXNEVR,

    /// Destination, source 1 & source 2 tile registers must be distinct.
    ND_ILUT_FLT_TRNETM_TRNETV_TVNETM,

    /// Destnation & source vector registers must be distinct.
    ND_ILUT_FLT_VRNEVV_VRNEVM,

    /// GPRs encoded in V & M must not be equal to RSP.
    ND_ILUT_FLT_RVNE4_RMNE4,

    /// GPRs encoded in V & M must be distinct.
    ND_ILUT_FLT_RVNERM,

} ND_ILUT_TYPE;


// Index definitions
#define ND_ILUT_INDEX_MOD_MEM           0
#define ND_ILUT_INDEX_MOD_REG           1

// Mandatory prefixes.
#define ND_ILUT_INDEX_MAN_PREF_NP       0
#define ND_ILUT_INDEX_MAN_PREF_66       1
#define ND_ILUT_INDEX_MAN_PREF_F3       2
#define ND_ILUT_INDEX_MAN_PREF_F2       3

// Operating mode.
#define ND_ILUT_INDEX_MODE_NONE         0
#define ND_ILUT_INDEX_MODE_16           1
#define ND_ILUT_INDEX_MODE_32           2
#define ND_ILUT_INDEX_MODE_64           3

// Operand size.
#define ND_ILUT_INDEX_DSIZE_NONE        0
#define ND_ILUT_INDEX_DSIZE_16          1
#define ND_ILUT_INDEX_DSIZE_32          2
#define ND_ILUT_INDEX_DSIZE_64          3
#define ND_ILUT_INDEX_DSIZE_D64         4
#define ND_ILUT_INDEX_DSIZE_F64         5

// Address size.
#define ND_ILUT_INDEX_ASIZE_NONE        0
#define ND_ILUT_INDEX_ASIZE_16          1
#define ND_ILUT_INDEX_ASIZE_32          2
#define ND_ILUT_INDEX_ASIZE_64          3

// Misc conditions.
#define ND_ILUT_INDEX_AUX_NONE          0
#define ND_ILUT_INDEX_AUX_REPZ          1
#define ND_ILUT_INDEX_AUX_REP           2
#define ND_ILUT_INDEX_AUX_REXB          3
#define ND_ILUT_INDEX_AUX_REXW          4
#define ND_ILUT_INDEX_AUX_MO64          5
#define ND_ILUT_INDEX_AUX_RIPREL        6
#define ND_ILUT_INDEX_AUX_REX2          7
#define ND_ILUT_INDEX_AUX_REX2W         8

// Specific features for instructions that map on the wide NOP space.
#define ND_ILUT_FEATURE_NONE            0
#define ND_ILUT_FEATURE_MPX             1
#define ND_ILUT_FEATURE_CET             2
#define ND_ILUT_FEATURE_CLDEMOTE        3
#define ND_ILUT_FEATURE_PITI            4
#define ND_ILUT_FEATURE_MOVRS           5
#define ND_ILUT_FEATURE_BHI             6

// Table sizes.
#define ND_ILUT_SIZE_OPCODE             256
#define ND_ILUT_SIZE_MODRM_MOD          2
#define ND_ILUT_SIZE_MODRM_REG          8
#define ND_ILUT_SIZE_MODRM_RM           8
#define ND_ILUT_SIZE_MPREFIX            4
#define ND_ILUT_SIZE_AUXILIARY          10
#define ND_ILUT_SIZE_VENDOR             16
#define ND_ILUT_SIZE_FEATURE            8
#define ND_ILUT_SIZE_MODE               4
#define ND_ILUT_SIZE_ASIZE              4
#define ND_ILUT_SIZE_DSIZE              6
#define ND_ILUT_SIZE_EX_M               32
#define ND_ILUT_SIZE_EX_PP              4
#define ND_ILUT_SIZE_EX_L               4
#define ND_ILUT_SIZE_EX_W               2
#define ND_ILUT_SIZE_EX_ND              2
#define ND_ILUT_SIZE_EX_NF              2
#define ND_ILUT_SIZE_EX_SC              16
#define ND_ILUT_SIZE_EX_LPDF            64
#define ND_ILUT_SIZE_FILTER             1


typedef struct _ND_TABLE_INSTRUCTION
{
    ND_UINT32       Type;       // ND_ILUT_INSTRUCTION
    ND_UINT16       Index;      // Index inside gInstructions
    ND_UINT16       Reserved;   // Reserved for future use.
} ND_TABLE_INSTRUCTION, *PND_TABLE_INSTRUCTION;

// Generic table type.
typedef struct _ND_TABLE
{
    ND_UINT32       Type;       // One of ND_ILUT*, indicating the type of the table.
    ND_UINT32       Reserved;
#ifdef _MSC_VER
#pragma warning(suppress: 4200) // nonstandard extension used: zero-sized array in struct/union
    const void      *Table[];   // Size depends on underlying table type.
#else
    const void      *Table[];
#endif
} ND_TABLE, *PND_TABLE;

typedef struct _ND_TABLE_OPCODE
{
    ND_UINT32       Type;       // ND_ILUT_OPCODE
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_OPCODE];
} ND_TABLE_OPCODE, *PND_TABLE_OPCODE;

typedef struct _ND_TABLE_MODRM_MOD
{
    ND_UINT32       Type;       // ND_ILUT_MODRM_MOD
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_MODRM_MOD];
} ND_TABLE_MODRM_MOD, *PND_TABLE_MODRM_MOD;

typedef struct _ND_TABLE_MODRM_REG
{
    ND_UINT32       Type;       // ND_ILUT_MODRM_REG
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_MODRM_REG];
} ND_TABLE_MODRM_REG, *PND_TABLE_MODRM_REG;

typedef struct _ND_TABLE_MODRM_RM
{
    ND_UINT32       Type;       // ND_ILUT_MODRM_RM
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_MODRM_RM];
} ND_TABLE_MODRM_RM, *PND_TABLE_MODRM_RM;

typedef struct _ND_TABLE_MPREFIX
{
    ND_UINT32       Type;       // ND_ILUT_MAN_PREFIX
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_MPREFIX];
} ND_TABLE_MPREFIX, *PND_TABLE_MPREFIX;

typedef struct _ND_TABLE_AUXILIARY
{
    ND_UINT32       Type;       // ND_ILUT_AUXILIARY
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_AUXILIARY];
} ND_TABLE_AUXILIARY, *PND_TABLE_AUXILIARY;

typedef struct _ND_TABLE_VENDOR
{
    ND_UINT32       Type;       // ND_ILUT_VENDOR
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_VENDOR];
} ND_TABLE_VENDOR;

typedef struct _ND_TABLE_FEATURE
{
    ND_UINT32       Type;       // ND_ILUT_FEATURE
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_FEATURE];
} ND_TABLE_FEATURE;

typedef struct _ND_TABLE_MODE
{
    ND_UINT32       Type;       // ND_ILUT_MODE
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_MODE];
} ND_TABLE_MODE, *PND_TABLE_MODE;

typedef struct _ND_TABLE_ASIZE
{
    ND_UINT32       Type;       // ND_ILUT_ASIZE
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_ASIZE];
} ND_TABLE_ASIZE, *PND_TABLE_ASIZE;

typedef struct _ND_TABLE_DSIZE
{
    ND_UINT32       Type;       // ND_ILUT_DSIZE
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_DSIZE];
} ND_TABLE_DSIZE, *PND_TABLE_DSIZE;

typedef struct _ND_TABLE_EX_M
{
    ND_UINT32       Type;       // ND_ILUT_EX_M
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_M];
} ND_TABLE_EX_M, *PND_TABLE_EX_M;

typedef struct _ND_TABLE_EX_PP
{
    ND_UINT32       Type;       // ND_ILUT_EX_PP
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_PP];
} ND_TABLE_EX_PP, *PND_TABLE_EX_PP;

typedef struct _ND_TABLE_EX_L
{
    ND_UINT32       Type;       // ND_ILUT_EX_L
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_L];
} ND_TABLE_EX_L, *PND_TABLE_EX_L;

typedef struct _ND_TABLE_EX_W
{
    ND_UINT32       Type;       // ND_ILUT_EX_W
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_W];
} ND_TABLE_EX_W, *PND_TABLE_EX_W;

typedef struct _ND_TABLE_EX_ND
{
    ND_UINT32       Type;       // ND_ILUT_EX_ND
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_ND];
} ND_TABLE_EX_ND, *PND_TABLE_EX_ND;

typedef struct _ND_TABLE_EX_NF
{
    ND_UINT32       Type;       // ND_ILUT_EX_NF
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_NF];
} ND_TABLE_EX_NF, *PND_TABLE_EX_NF;

typedef struct _ND_TABLE_EX_SC
{
    ND_UINT32       Type;       // ND_ILUT_EX_SC
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_SC];
} ND_TABLE_EX_SC, *PND_TABLE_EX_SC;

typedef struct _ND_TABLE_EX_LPDF
{
    ND_UINT32       Type;       // ND_ILUT_EX_LPDF
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_EX_LPDF];
} ND_TABLE_EX_LPDF, *PND_TABLE_EX_LPDF;

typedef struct _ND_TABLE_FILTER
{
    ND_UINT32       Type;       // ND_ILUT_FLT*
    ND_UINT32       Reserved;
    const void      *Table[ND_ILUT_SIZE_FILTER];
} ND_TABLE_FILTER;


//
// Instruction database entry.
//
typedef struct _ND_IDBE
{
    ND_UINT16       Instruction;    // Instruction identifier. Check ND_INS_CLASS definitions.
    ND_UINT8        Category;       // Instruction category. Check ND_INS_TYPE.
    ND_UINT8        IsaSet;         // Instruction set. Check ND_INS_SET.
    ND_UINT16       Mnemonic;       // Mnemonic (index inside the global mnemonic table).
    ND_UINT16       ValidPrefixes;  // Accepted prefixes.
    ND_UINT32       ValidModes;     // Valid operating modes for the instruction.
    ND_UINT8        ValidDecorators;// Accepted decorators (valid for EVEX instructions).
    ND_UINT8        OpsCount;       // Low 4 bits: explicit operands count; high 4 bits: implicit ops count.
    ND_UINT8        TupleType;      // EVEX tuple type.
    ND_UINT8        ExcType;        // SSE/VEX/EVEX/OPMASK/AMX/APX exception type.
    ND_UINT8        FpuFlags;       // FPU status word C0, C1, C2 & C3 access type.
    ND_UINT8        EvexMode;       // EVEX prefix extension type.
    ND_UINT8        SimdExc;        // SIMD Floating-Point Exceptions.
    ND_UINT8        Ipb;            // Instruction payload bytes (such as immediate values).

    // Various component access, pre-decoded.
    ND_UINT8        CsAccess;       // CS access. Indicative of far branches.
    ND_UINT8        RipAccess;      // RIP access. Modified by branches.
    ND_UINT8        RflAccess;      // RFLAGS access.
    ND_UINT8        Mem1Access;     // Memory access for explicit modrm operand. Valid only if mod is mem.
    ND_UINT8        Mem2Access;     // Memory access for encoding independnt accesses.
    ND_UINT8        StkAccess;      // Stack access.
    ND_UINT8        StkWords;       // Stack words accessed.

    // Per-flag access. Undefined flags will have their bit set in both the "Set" and "Cleared" mask, since a flag
    // cannot be both cleared and set.
    ND_UINT32       TestedFlags;    // Tested flags.
    ND_UINT32       ModifiedFlags;  // Modified flags.
    ND_UINT32       SetFlags;       // Flags that are always set to 1.
    ND_UINT32       ClearedFlags;   // Flags that are always cleared.

    ND_UINT64       Attributes;     // Instruction attributes.
    ND_UINT64       CpuidFlag;      // Required CPUID feature flag.

    // List of operands. Up to 10 implicit and explicit operands stored in DB.
    ND_UINT64       Operands[10];

} ND_IDBE, *PND_IDBE;


//
// The following definitions are per-operand specific.
//
// Packed operand structure:
// Byte 0: operand type
// Byte 1: operand size
// Byte 2: operand flags
// Byte 3: operand access
// Byte 4: operand decorators
// Byte 5: operand block addressing mode - 0 if not block addressing
//
#define ND_OP(type, size, flags, acc, dec, block)       (((ND_UINT64)((type) & 0xFF) << 0)   |    \
                                                         ((ND_UINT64)((size) & 0xFF) << 8)   |    \
                                                         ((ND_UINT64)((flags) & 0xFF) << 16) |    \
                                                         ((ND_UINT64)((acc) & 0xFF) << 24)   |    \
                                                         ((ND_UINT64)((dec) & 0xFF) << 32)   |    \
                                                         ((ND_UINT64)((block) & 0xFF) << 40))

#define OP ND_OP

#define ND_OPS_CNT(expo, impo)              ((expo) | ((impo) << 4))
#define ND_EXP_OPS_CNT(cnt)                 ((cnt) & 0xF)
#define ND_IMP_OPS_CNT(cnt)                 ((cnt) >> 4)

#define ND_OP_TYPE(op)                      ((op) & 0xFF)
#define ND_OP_SIZE(op)                      (((op) >> 8) & 0xFF)
#define ND_OP_FLAGS(op)                     (((op) >> 16) & 0xFF)
#define ND_OP_ACCESS(op)                    (((op) >> 24) & 0xFF)
#define ND_OP_DECORATORS(op)                (((op) >> 32) & 0xFF)
#define ND_OP_BLOCK(op)                     (((op) >> 40) & 0xFF)




//
// Operand size descriptors. These are internal and stored inside the specifier. They must be interpreted
// accordingly to extract the actual size used in the instruction. These should not be used by anyone using
// the disassembler. Use the "Size" and "RawSize" fields inside the operand instead.
//
// For info on what each enum means, check out the valid_opsize field inside disasmlib.py.
//
typedef enum _ND_OPERAND_SIZE_SPEC
{
    ND_OPS_none = 0,
    ND_OPS_0,
    ND_OPS_asz,
    ND_OPS_ssz,
    ND_OPS_a,
    ND_OPS_c,
    ND_OPS_b,
    ND_OPS_w,
    ND_OPS_d,
    ND_OPS_q,
    ND_OPS_dq,
    ND_OPS_qq,
    ND_OPS_oq,
    ND_OPS_v,
    ND_OPS_y,
    ND_OPS_yf,
    ND_OPS_z,
    ND_OPS_s,
    ND_OPS_p,
    ND_OPS_fa,
    ND_OPS_fw,
    ND_OPS_fd,
    ND_OPS_fq,
    ND_OPS_ft,
    ND_OPS_fe,
    ND_OPS_fs,
    ND_OPS_l,
    ND_OPS_rx,
    ND_OPS_cl,
    ND_OPS_sd,
    ND_OPS_ss,
    ND_OPS_sh,
    ND_OPS_ps,
    ND_OPS_pd,
    ND_OPS_ph,
    ND_OPS_ev,
    ND_OPS_qv,
    ND_OPS_hv,
    ND_OPS_x,
    ND_OPS_uv,
    ND_OPS_fv,
    ND_OPS_t,       // Tile register size, can be up to 1K.
    ND_OPS_384,     // 384 bit Key Locker handle.
    ND_OPS_512,     // 512 bit Key Locker handle.
    ND_OPS_4096,    // 4096 bit MSR address/value table, used by RDMSRLIST/WRMSRLIST.
    // Stack sizes - indicates number of words. Also, hybrid sizes - sizes where from a large register (say 32 bit GPR)
    // only a smaller amount of data is used (for example, 8 bit).
    ND_OPS_v2,
    ND_OPS_v3,
    ND_OPS_v4,
    ND_OPS_v5,
    ND_OPS_v8,
    // 4 + 8 bytes accessed on the shadow stack by the SAVPREVSSP instruction.
    ND_OPS_12,
    // MIB
    ND_OPS_mib,
    // VSIB sizes (for both the index and the accessed data).
    ND_OPS_vm32x,
    ND_OPS_vm32y,
    ND_OPS_vm32z,
    ND_OPS_vm32h,
    ND_OPS_vm32n,
    ND_OPS_vm64x,
    ND_OPS_vm64y,
    ND_OPS_vm64z,
    ND_OPS_vm64h,
    ND_OPS_vm64n,
    // Used for arbitrary sized buffers.
    ND_OPS_unknown,

} ND_OPERAND_SIZE_SPEC;


//
// Operand types. These definitions are internal and have to be interpreted in order to find out what each
// operand represents. These should not be used by anyone using the disassembler. Use the "Type" field inside
// the operand structure instead.
//
// For more info on what each operand type means, please check out the valid_optype field inside disasmlib.py.
//
typedef enum _ND_OPERAND_TYPE_SPEC
{
    ND_OPT_A,
    ND_OPT_B,
    ND_OPT_C,
    ND_OPT_D,
    ND_OPT_E,
    ND_OPT_F,
    ND_OPT_G,
    ND_OPT_H,
    ND_OPT_I,
    ND_OPT_I1,
    ND_OPT_I2,
    ND_OPT_J,
    ND_OPT_K,
    ND_OPT_L,
    ND_OPT_M,
    ND_OPT_N,
    ND_OPT_O,
    ND_OPT_P,
    ND_OPT_Q,
    ND_OPT_R,
    ND_OPT_S,
    ND_OPT_T,
    ND_OPT_U,
    ND_OPT_V,
    ND_OPT_W,
    ND_OPT_X,
    ND_OPT_Y,
    ND_OPT_Z,
    ND_OPT_rB,
    ND_OPT_mB,
    ND_OPT_rK,
    ND_OPT_vK,
    ND_OPT_mK,
    ND_OPT_aK,
    ND_OPT_rM,
    ND_OPT_mM,
    ND_OPT_rT,
    ND_OPT_mT,
    ND_OPT_vT,
    ND_OPT_dfv,
    ND_OPT_1,

    // These are implicit arguments inside instructions.

    // Special registers.
    ND_OPT_rIP,
    ND_OPT_MXCSR,
    ND_OPT_PKRU,
    ND_OPT_SSP,
    ND_OPT_UIF,

    // General Purpose Registers.
    ND_OPT_AH,
    ND_OPT_rAX,
    ND_OPT_rCX,
    ND_OPT_rDX,
    ND_OPT_rBX,
    ND_OPT_rSP,
    ND_OPT_rBP,
    ND_OPT_rSI,
    ND_OPT_rDI,
    ND_OPT_rR8,
    ND_OPT_rR9,
    ND_OPT_rR11,

    // Segment registers.
    ND_OPT_CS,
    ND_OPT_SS,
    ND_OPT_DS,
    ND_OPT_ES,
    ND_OPT_FS,
    ND_OPT_GS,

    // FPU registers.
    ND_OPT_ST0,
    ND_OPT_STi,

    // SSE registers.
    ND_OPT_XMM0,
    ND_OPT_XMM1,
    ND_OPT_XMM2,
    ND_OPT_XMM3,
    ND_OPT_XMM4,
    ND_OPT_XMM5,
    ND_OPT_XMM6,
    ND_OPT_XMM7,

    // Implicit memory operands.
    ND_OPT_pAX,         // [rAX]
    ND_OPT_pCX,         // [rCX]
    ND_OPT_pBXAL,       // [rBX + AL]
    ND_OPT_pDI,         // [rDI]
    ND_OPT_pBP,         // [rBP]
    ND_OPT_SHS,         // Shadow stack.
    ND_OPT_SHSP,        // Shadow stack pointed by the SSP.
    ND_OPT_SHS0,        // Shadow stack pointed by the SSP.
    ND_OPT_SMT,         // Source MSR table, encoded in [RSI].
    ND_OPT_DMT,         // Destination MSR table, encoded in [RDI].

    // Special immediates.
    ND_OPT_m2zI,

    // Misc CR/XCR/MSR/SYS registers.
    ND_OPT_CR0,
    ND_OPT_IDTR,
    ND_OPT_GDTR,
    ND_OPT_LDTR,
    ND_OPT_TR,
    ND_OPT_X87CONTROL,
    ND_OPT_X87TAG,
    ND_OPT_X87STATUS,
    ND_OPT_MSR,
    ND_OPT_XCR,
    ND_OPT_TSC,
    ND_OPT_TSCAUX,
    ND_OPT_SEIP,
    ND_OPT_SESP,
    ND_OPT_SCS,
    ND_OPT_STAR,
    ND_OPT_LSTAR,
    ND_OPT_FMASK,
    ND_OPT_FSBASE,
    ND_OPT_GSBASE,
    ND_OPT_KGSBASE,
    ND_OPT_XCR0,
    ND_OPT_BANK,

} ND_OPERAND_TYPE_SPEC;


//
// Operand flags.
//
#define ND_OPF_OPDEF                0x01    // The operand is default, no need to show it in disassembly.
#define ND_OPF_OPSIGNEXO1           0x02    // The operand is sign-extended to the first operands' size.
#define ND_OPF_OPSIGNEXDW           0x04    // The operand is sign-extended to the default word size.


//
// Operand access.
//
#define ND_OPA_N                    0x00    // The operand is not accessed.
#define ND_OPA_R                    0x01    // The operand is read.
#define ND_OPA_W                    0x02    // The operand is written.
#define ND_OPA_CR                   0x04    // The operand is read conditionally.
#define ND_OPA_CW                   0x08    // The operand is written conditionally.
#define ND_OPA_RW                   0x03    // Read-Write access.
#define ND_OPA_RCW                  0x09    // Read-Conditional Write access.
#define ND_OPA_CRW                  0X06    // Conditional Read-Write access.
#define ND_OPA_CRCW                 0x0C    // Conditional Read-Conditional Write access.
#define ND_OPA_P                    0x10    // The operand is memory, and it is prefetched.


//
// Operand decorator flags.
//
#define ND_OPD_MASK                 0x01    // Mask accepted.
#define ND_OPD_ZERO                 0x02    // Zeroing accepted.
#define ND_OPD_B32                  0x04    // 32 bit broadcast supported.
#define ND_OPD_B64                  0x08    // 64 bit broadcast supported.
#define ND_OPD_SAE                  0x10    // Suppress all exceptions supported.
#define ND_OPD_ER                   0x20    // Embedded rounding supported.
#define ND_OPD_B16                  0x40    // 16 bit broadcast supported.

#define ND_OPD_BCAST                (ND_OPD_B16 | ND_OPD_B32 | ND_OPD_B64)


//
// Instruction immediate payload bytes.
//
#define ND_IPB_NONE                 0x00    // No immediate/payload bytes encoded.
#define ND_IPB_I_b                  0x01    // Immediate byte.
#define ND_IPB_I_w                  0x02    // Immediate word.
#define ND_IPB_I_d                  0x03    // Immediate dword.
#define ND_IPB_I_z                  0x04    // Immediate word/dword.
#define ND_IPB_I_v                  0x05    // Immediate word/dword/qword.
#define ND_IPB_I_wb                 0x06    // Immediate word + byte.
#define ND_IPB_I_bb                 0x07    // Immediate word + byte.
#define ND_IPB_J_b                  0x08    // Relative offset byte.
#define ND_IPB_J_z                  0x09    // Relative offset word/dword.
#define ND_IPB_A_p                  0x0A    // Address far pointer.
#define ND_IPB_A_q                  0x0B    // Address near pointer.
#define ND_IPB_O_a                  0x0C    // Moffset.
#define ND_IPB_L_b                  0x0D    // Immediate encoding SSE register.


const ND_IDBE *
NdIdbeGetEntry(
    ND_UINT32 Index
);

const char *
NdIdbeGetMnemonic(
    ND_UINT32 Index
);

#endif // BDX86_TABLEDEFS_H
