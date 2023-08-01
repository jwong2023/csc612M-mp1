section .text
bits 64
default rel		; []
global SIMD_dotprod

;extern void SIMD_dotprod(int VECTOR_SIZE, int* dp_simd, int* a, int* b, int* c);

SIMD_dotprod:
; rcx - VECTOR_SIZE, rdx - pointer to out, r8 - pointer to in, r9 - pointer to in

	shr rcx, 3 ; 2^3 = 8
    vpxor ymm4, ymm4
	vpxor ymm3, ymm3

	L1:
		vmovdqu ymm1, [r8]
		vmovdqu ymm2, [r9]

		vpmulld ymm3, ymm1, ymm2
		;vpaddd ymm4, ymm3

		vmovdqu [rdx], ymm3

		add r8, 32 ; 4 bytes * 8 elements
		add r9, 32
		add rdx, 32

	loop L1


	ret
