#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//extern void asmhello(); 

void daxpy_c(long n, double A, double* X, double* Y, double* Z);

int main() {
	//CLOCK 
	clock_t start, end;
	double time_for_C;

	


	//N
	//int n = 1 << 20; // 2^20
	//int n = 1 << 24; // 2^24
	int n = 1 << 28; // 2^30 closest to this

	//A
	double A = (double)(rand() % 1000) / 10.0; //Random values between 0.0 and 100.0
	printf("%.2f\n", A);

	//input for n and A
	/*
	* printf("n: ");
	scanf_s("%d", &n);
	printf("A: ");
	scanf_s("%lf", &A);
	*/
	srand(time(NULL));

	//allocating memory for X Y Z 
	double* X = (double*)malloc(n * sizeof(double));
	double* Y = (double*)malloc(n * sizeof(double));
	double* Z = (double*)malloc(n * sizeof(double));
	
	

	
	/* PREVIOUS for smaller version
	* 	//X
	for (int i = 0; i < n; i++) {
		double X = (double)(rand() % 1000) / 10.0; // Random values between 0.0 and 100.0
		//printf( "%.2f ", X);
	}
	printf("\n");
	//Y
	for (int i = 0; i < n; i++) {
		double Y = (double)(rand() % 1000) / 10.0; // Random values between 0.0 and 100.0
		//printf("%.2f ", Y);
	}

	*/
	
	for (long i = 0;i < n;i++) {
		X[i] = (double)(rand() % 1000) / 10.0; //Random values between 0.0 and 100.0
		Y[i] = (double)(rand() % 1000) / 10.0; //Random values between 0.0 and 100.0
	}


	//C KERNEL AND CLOCK TIME
	start = clock();
	daxpy_c(n, A, X, Y, Z);
	end = clock();
	time_for_C = ((double)(end - start)) / CLOCKS_PER_SEC *1000;


	printf("\nOUTPUT Z: ");
	for (int i = 0;i < 10; i++) {
		printf_s("%.2f ", Z[i]);
	}
	printf("\n");
	printf("C time: %f ms\n", time_for_C);



	free(X);
	free(Y);
	free(Z);

	return 0;


}