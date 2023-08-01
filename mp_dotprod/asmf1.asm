
section .text
bits 64
default rel
global x86_dotprod

; extern void x86_dotprod(int VECTOR_SIZE, int* dp_86, int* a, int* b);

x86_dotprod:
; rcx - VECTOR_SIZE, rdx - pointer to out, r8 - pointer to in, r9 - pointer to in

    ; nasm
    pxor xmm4, xmm4

    L1:
    movd xmm1, [r8]
    movd xmm2, [r9]
    pmulld xmm1, xmm2
    paddd xmm4, xmm1
    movd [rdx], xmm4

    add r8, 4
    add r9, 4
    add rdx, 4
    loop L1
    

    ret
