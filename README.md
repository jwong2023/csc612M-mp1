# csc612M-mp1
Dot product

CUDA link: https://colab.research.google.com/drive/1DjYHZVWW6QBM49MAIFgJGM9QdkUpH48y?authuser=3#scrollTo=iuKauI81YB_v

**Comparative Execution Time (Average from 30 runs) of Different Kernels**

**2^20**
C: 1033.33 microseconds
x86-64: 633.33
x86 SIMD: 333.33
CUDA:

**2^24**
C:
x86-64: 
x86 SIMD:
CUDA:

**2^28**
C:
x86-64: 
x86 SIMD:
CUDA:

**Analysis**
Unfortunately, the local PC does not reflect an accurate time taken, but the average is still taken from repeated runs.

The ordering of kernel run time is as follows from fastest to slowest: SIMD, CUDA, by x86, and then C. This is observed from 2^24 and 2^28 elements. But for 2^20 elements, CUDA was faster than all three. The reason of this could be that the power of packed or parallel processing as many as SIMD can handle really shows its capability when dealing with a growing number of elements.


**Screenshots**

C program, x86-64, SIMD YMM register (in order)


Small sized (10,000)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/2c47f400-0db7-4d72-9102-ba015d12ffbc)

Single runs:
2^20
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/2021808c-7a9b-417b-8db3-fab6196658a0)
2^24
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/1c07c42d-460b-461b-94eb-076624a08ae0)
2^28
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/c8314767-ff90-4638-8011-936d9b85f1b6)

Average of 30 runs:
2^20
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/4c084638-5750-4a50-9b62-1db4c63fd2b9)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/6561dae0-1b10-4ecf-a9f5-0eec9b4791f0)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/70155808-40d1-4d6d-a040-506d2e461abd)
2^24
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/59e11a29-117d-4740-bd8a-9e8e082b2420)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/fdfffcb9-bc2b-409c-80aa-ec181b19a32d)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/fd0efdce-091c-4d53-a284-d197c2adf42e)
2^28



CUDA
2^20
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/810b51e7-52bc-4834-a758-a240f77b2f53)

2^24
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/b75d6d58-232b-459c-91a4-9f29ec70157c)

2^28
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/6dc9410c-4aad-4e33-80c3-7e891aee5f84)



