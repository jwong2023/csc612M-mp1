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

The ordering of kernel run time is as follows from fastest to slowest: SIMD, CUDA, x86, and then C. This is observed from 2^24 and 2^28 elements. But for 2^20 elements, CUDA was faster than all three. The reason of this could be that the power of packed or parallel processing as many as SIMD can handle really shows its capability when dealing with a growing number of elements.


**Screenshots**

C program, x86-64, SIMD YMM register, CUDA (in order)


Small sized (10,000)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/2c47f400-0db7-4d72-9102-ba015d12ffbc)

Average of 30 runs:
2^20

![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/c8a20486-75ad-4042-95b0-5a5e3912a508)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/11178b84-c53e-43ee-a766-2070e04e0937)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/e433241a-e1a1-4084-8214-4e956e00348a)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/f4e0c7ab-07fc-49cd-9006-773ba38cc2ce)

2^24

![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/05ad7a9e-17b7-4826-9734-fb2d84446e0a)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/f0475b65-19b9-49f2-b9a1-0e3237a8f56e)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/5fac3f90-32d6-4849-872b-3301d15588ec)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/82720669-b140-4d10-93e3-7440b5aeedb4)


2^28*

(30 loops of 2^28 crashed the PC, hence showing below 2^27, aligned in CUDA to show 2^27)

![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/c7035589-755a-4a7b-9691-f37a25f80191)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/a8d2fb97-453c-40ab-bd42-c9341a7df82a)

![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/a0bd2e52-337f-4d03-87e7-64c23320523f)







