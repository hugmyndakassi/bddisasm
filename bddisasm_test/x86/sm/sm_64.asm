        bits 64
        
        db 0xc4, 0x62, 0x78, 0xda, 0xc7         ; VSM3MSG1  xmm8, xmm0, xmm7
        db 0xc4, 0x62, 0x78, 0xda, 0x01         ; VSM3MSG1  xmm8, xmm0, xmmword ptr [rcx]
        db 0xc4, 0x62, 0x79, 0xda, 0xc7         ; VSM3MSG2  xmm8, xmm0, xmm7
        db 0xc4, 0x62, 0x79, 0xda, 0x01         ; VSM3MSG2  xmm8, xmm0, xmmword ptr [rcx]
        
        db 0xc4, 0x62, 0x7a, 0xda, 0xc7         ; VSM4KEY4  xmm8, xmm0, xmm7
        db 0xc4, 0x62, 0x7a, 0xda, 0x01         ; VSM4KEY4  xmm8, xmm0, xmmword ptr [rcx]
        db 0xc4, 0x62, 0x7b, 0xda, 0xc7         ; VSM4RNDS4 xmm8, xmm0, xmm7
        db 0xc4, 0x62, 0x7b, 0xda, 0x01         ; VSM4RNDS4 xmm8, xmm0, xmmword ptr [rcx]
        
        db 0xc4, 0x62, 0x7e, 0xda, 0xc7         ; VSM4KEY4  ymm8, ymm0, ymm7
        db 0xc4, 0x62, 0x7e, 0xda, 0x01         ; VSM4KEY4  ymm8, ymm0, ymmword ptr [rcx]
        db 0xc4, 0x62, 0x7f, 0xda, 0xc7         ; VSM4RNDS4 ymm8, ymm0, ymm7
        db 0xc4, 0x62, 0x7f, 0xda, 0x01         ; VSM4RNDS4 ymm8, ymm0, ymmword ptr [rcx]
        
        db 0xc4, 0x63, 0x79, 0xde, 0xc7, 0xef   ; VSM3RNDS2 xmm8, xmm0, xmm7, 0xef
        db 0xc4, 0x63, 0x79, 0xde, 0x01, 0xef   ; VSM3RNDS2 xmm8, xmm0, xmmword ptr [rcx], 0xef
        
        