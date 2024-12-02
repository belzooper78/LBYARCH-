#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//extern void asmhello(); 
extern void daxpy_asm( double A, double* X, double* Y, double* Z, long n );

void daxpy_c(long n, double A, double* X, double* Y, double* Z);

int main() {
	//CLOCK 
	clock_t start, end, start2, end2;
	double time_for_C, time_for_asm;

	//N
	//int n = 4;
	//int n = 1 << 20; // 2^20
	//int n = 1 << 24; // 2^24
	int n = 1 << 28; // 2^30 closest to this

	srand(time(NULL));

	//A
	double A = (double)(rand() % 1000) / 10.0; //Random values between 0.0 and 100.0
	printf("%.2f\n", A);


	

	//allocating memory for X Y Z 
	double* X = (double*)malloc(n * sizeof(double));
	double* Y = (double*)malloc(n * sizeof(double));
	double* Z = (double*)malloc(n * sizeof(double));
	
	

	
	for (long i = 0;i < n;i++) {
		X[i] = (double)(rand() % 1000) / 10.0; //Random values between 0.0 and 100.0
		Y[i] = (double)(rand() % 1000) / 10.0; //Random values between 0.0 and 100.0
	}


	//C KERNEL AND CLOCK TIME
	start = clock();
	daxpy_c(n, A, X, Y, Z);
	end = clock();
	time_for_C = ((double)(end - start)) / CLOCKS_PER_SEC *1000;

	

	printf("\nOUTPUT Z in C: ");
	for (int i = 0;i < 10; i++) {
		printf_s("%.2f ", Z[i]);
	}
	printf("\n");
	printf("C time: %f ms\n", time_for_C);


	//for (int i = 0;i < 10; i++) {
	//	Z[i] = 0.0;	//testing
	//}

	start2 = clock();
	daxpy_asm(A, X, Y, Z,n);
	end2 = clock();
	time_for_asm = ((double)(end2 - start2)) / CLOCKS_PER_SEC * 1000;
	/////////////////////////////////////////
	printf("\nOUTPUT Z in asm: ");
	for (int i = 0;i < 10; i++) {
		printf_s("%.2f ", Z[i]);
	}
	printf("\nassembly time: %f ms\n", time_for_asm);

	free(X);
	free(Y);
	free(Z);

	return 0;


}