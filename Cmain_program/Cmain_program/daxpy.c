#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void daxpy_asm(long n, double A, double* X, double* Y, double* Z);

void daxpy_c(long n, double A, double* X, double* Y, double* Z) {
    for (int i = 0; i < n; i++) {
        Z[i] = A * X[i] + Y[i];
    }
}

int main() {
    //CLOCK 
    clock_t start, end;
    double time_for_C;

    int n = 1 << 28; 

    double A = (double)(rand() % 1000) / 10.0; 
    printf("%.2f\n", A);

    srand(time(NULL));

    double* X = (double*)malloc(n * sizeof(double));
    double* Y = (double*)malloc(n * sizeof(double));
    double* Z = (double*)malloc(n * sizeof(double));

    for (long i = 0; i < n; i++) {
        X[i] = (double)(rand() % 1000) / 10.0; 
        Y[i] = (double)(rand() % 1000) / 10.0;
    }

    //CLOCK
    start = clock();
    daxpy_asm(n, A, X, Y, Z); 
    end = clock();
    time_for_C = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("\nOUTPUT Z: ");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", Z[i]);
    }
    printf("\n");
    printf("C time: %f ms\n", time_for_C);

    free(X);
    free(Y);
    free(Z);

    return 0;
}
