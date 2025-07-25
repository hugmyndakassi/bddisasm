    bits 64
    
    ; srcdest == src1, src1 == src2 or srcdest == src2 => #UD.
    db 0xc4, 0xe2, 0x78, 0x5e, 0xC0                     ; TDPBUUD   tmm0, tmm0, tmm0
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x78, 0x5e, 0xC1                     ; TDPBUUD   tmm0, tmm1, tmm0
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x78, 0x5e, 0xC8                     ; TDPBUUD   tmm1, tmm0, tmm0
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x70, 0x5e, 0xC0                     ; TDPBUUD   tmm0, tmm0, tmm1
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    
    ; tileload or tilestore without SIB => #UD.
    db 0xc4, 0xe2, 0x79, 0x4b, 0x00                     ; TILELOADDT1 tmm0, [rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x7b, 0x4b, 0x00,                    ; TILELOADD tmm0, [rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x7a, 0x4b, 0x00                     ; TILESTORED tmm0, [rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    
    ; using vex.vvvv != 0b1111 => #UD
    db 0xc4, 0xe2, 0x70, 0x49, 0x00         ; LDTILECFG zmmword ptr [rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x71, 0x49, 0x00         ; STTILECFG zmmword ptr [rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    
    db 0xc4, 0xe2, 0x71, 0x4b, 0x04, 0x00   ; TILELOADDT1 tmm0, [rax+rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x73, 0x4b, 0x04, 0x00   ; TILELOADD tmm0, [rax+rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x72, 0x4b, 0x04, 0x00   ; TILESTORED tmm0, [rax+rax]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    
    db 0xc4, 0xe2, 0x71, 0x4b, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00   ; TILELOADDT1 tmm0, [rax+rax+0]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x73, 0x4b, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00   ; TILELOADD tmm0, [rax+rax+0]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x72, 0x4b, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00   ; TILESTORED tmm0, [rax+rax+0]
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    
    db 0xc4, 0xe2, 0x70, 0x49, 0xC0         ; TILERELEASE
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x73, 0x49, 0xC0         ; TILEZERO  tmm0
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
    db 0xc4, 0xe2, 0x73, 0x49, 0xf8         ; TILEZERO  tmm7
    db 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
