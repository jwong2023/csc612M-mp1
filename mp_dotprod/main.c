// Jane Wong CSC612M G01

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void x86_dotprod(int VECTOR_SIZE, int* sdot_86, int* a, int* b);
extern void SIMD_dotprod(int VECTOR_SIZE, int* sdot_simd, int* a, int* b);

#define N 10000

int dot_product(int n, int sdot, int a[], int b[])
{
    for (int i = 0; i < n; i++) {
        sdot += a[i] * b[i];
    }
    return sdot;
}

void init_vector(int n, int* v) {
    int a = 100;
    for (int i = 0; i < n; ++i) {
        v[i] = 1 + rand() % a;
        //printf("%d\n", v[i]);
    }

}

int main()
{
    srand((unsigned)time(0));
    clock_t start, end;
    const unsigned int VECTOR_SIZE = N;
    const unsigned int VECTOR_BYTES = VECTOR_SIZE * sizeof(int);
    int sdot = 0;
    int sdot_c = 0;
    double tot_time = 0.0f;


    // Create vectors with random values
    int* a, * b, * sdot_86, * sdot_simd, * c;
    a = (int*)malloc(VECTOR_BYTES);
    b = (int*)malloc(VECTOR_BYTES);
    sdot_86 = (int*)malloc(VECTOR_BYTES);
    sdot_simd = (int*)malloc(VECTOR_BYTES);

    init_vector(VECTOR_SIZE, a);
    init_vector(VECTOR_SIZE, b);

    //---------C version--------//

    for (int j = 0; j < 30; j++) {

        c = (int*)malloc(VECTOR_BYTES);
        sdot_c = 0;

        // Flush out cache
        dot_product(VECTOR_SIZE, sdot, a, b);

        // Compute dot product
        start = clock();
        sdot_c = dot_product(VECTOR_SIZE, sdot, a, b);
        end = clock();
        double time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

        // aggregate time
        tot_time += time_taken;

    }

    // compute average time for all j runs
    double avg_time = tot_time / 30;
    tot_time = 0.0f;

    // Output
    printf("Dot product is %d\n", sdot_c);
    printf("C function took %f microseconds for vector sized %d \n\n", avg_time, VECTOR_SIZE);

    //---------x86-64--------//

    for (int j = 0; j < 30; j++) {

        sdot_86 = (int*)malloc(VECTOR_BYTES);

        // Flush out cache
        x86_dotprod(VECTOR_SIZE, sdot_86, a, b);

        // initialize
        for (int i = 0; i < N; i++) {
            sdot_86[i] = 0;
        }

        // Compute dot product
        start = clock();
        x86_dotprod(VECTOR_SIZE, sdot_86, a, b);
        end = clock();
        double time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

        // aggregate time
        tot_time += time_taken;

        //for (int i = 0; i < VECTOR_SIZE; ++i) {
        //    printf("A %d\n", a[i]);
        //    printf("B %d\n", b[i]);
        //    printf("x86 dot product %d %d\n", i, sdot_86[i]);
        //}

        // Error check
        printf("x86 dot product %d\n", sdot_86[N - 1]);
        if (sdot_86[N - 1] != sdot_c) {
            printf("x86 calculated the wrong dot product\n");
        }
        else {
            printf("x86 calculated the right dot product\n");
        }

    }

    // compute average time for all j runs
    avg_time = tot_time / 30;
    tot_time = 0.0f;


    // Output
    printf("x86 function took %f microseconds for vector sized %d \n\n", avg_time, VECTOR_SIZE);

    //---------SIMD--------//

    for (int j = 0; j < 30; j++) {

        sdot_simd = (int*)malloc(VECTOR_BYTES);

        // Flush out cache
        SIMD_dotprod(VECTOR_SIZE, sdot_simd, a, b);

        // Compute dot product
        start = clock();
        SIMD_dotprod(VECTOR_SIZE, sdot_simd, a, b);
        end = clock();
        double time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

        // aggregate time
        tot_time += time_taken;

        int total_sdot = 0;
        for (int i = 0; i < VECTOR_SIZE; ++i) {
            //    printf("A %d\n", a[i]);
            //    printf("B %d\n", b[i]);
            //    printf("SIMD dot product %d\n", sdot_simd[i]);
            total_sdot += sdot_simd[i];
        }
        printf("SIMD final dot product %d\n", total_sdot);

        // Error check
        if (total_sdot != sdot_c) {
            printf("SIMD calculated the wrong dot product\n");
        }
        else {
            printf("SIMD calculated the right dot product\n");
        }

    }

    // compute average time for all j runs
    avg_time = tot_time / 30;
    tot_time = 0.0f;


    // Output
    printf("SIMD function took %f microseconds for vector sized %d \n\n", avg_time, VECTOR_SIZE);



    // Free memory
    free(a);
    free(b);
    free(sdot_86);
    free(sdot_simd);

    // End
    return 0;
}