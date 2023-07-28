# csc612M-mp1
Dot product

CUDA link: https://colab.research.google.com/drive/1DjYHZVWW6QBM49MAIFgJGM9QdkUpH48y?authuser=3#scrollTo=iuKauI81YB_v

**Comparative Execution Time (Average from 30 runs) of Different Kernels**

**2^20**
C: 1400.00 microseconds

x86-64: 766.67 microseconds

x86 SIMD: 533.33 microseconds

CUDA: 1859.8 + 394.0 (overhead) = 2253.80 microseconds

**2^24**
C: 22366.67 microseconds

x86-64: 12133.33 microseconds

x86 SIMD: 11333.33 microseconds

CUDA: 40923.0 + 482.2 (overhead) = 41405.26 microseconds

**2^28**
C: 189500.00 microseconds

x86-64: 128533.33 microseconds

x86 SIMD: 114933.33 microseconds

CUDA: 233690.0 + 410.7537 (overhead) = 234100.80 microseconds

**Analysis**

The average is still taken from repeated runs (30 times).

The ordering of kernel run time is as follows from fastest to slowest: SIMD, x86, C, then CUDA. The reason of this is that the power of packed or parallel processing is demonstrated by SIMD as it can handle as many as it can, showing its capability when dealing with a growing number of elements. SIMD will always be better than x86 and C due to the fact that we are able to do multiple processes in a unit of time. SIMD also shows more flexibility while still being dependent on the CPU cores, vs CUDA that is limited with the GPU hardware and needs to consider the time transferring data between CPU and GPU. It was observed that when running only single instance CUDA was showing to be faster than C, hence further improvement on the code must be done.

This acknowledges also that the program for x86-64 is accurate only for small numbers (tested 10,000 elements).

**Screenshots**

C program, x86-64, SIMD YMM register, CUDA (in order)


Small sized (10,000)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/17066e83-f6a3-4f7e-865f-54f2a216c65c)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/bde7a502-5e82-4727-a207-31f555560736)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/34ce7f37-aaf0-4dd6-aac7-a7f3c483f705)


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
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/7b23cf42-bcc2-42ba-b616-79ea350a7be0)
![image](https://github.com/jwong2023/csc612M-mp1/assets/140816677/a0bd2e52-337f-4d03-87e7-64c23320523f)







