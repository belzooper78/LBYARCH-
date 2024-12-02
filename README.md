# LBYARCH-MP2
By Nico Diego and Ryan Villanueva

DAXPY Kernel Project (C and x86-64 Assembly)
This project demonstrates the implementation of the DAXPY (A * X + Y) function in both C and x86-64 Assembly. The project aims to compare the performance of these two implementations, utilizing SIMD (Single Instruction, Multiple Data) registers for scalar floating-point operations. We also include performance benchmarking and correctness verification to ensure the accuracy of the outputs.

Project Structure

C Program (daxpy.c):

	-Implements the DAXPY operation in C.
 
	-Iterates through the vectors X and Y, and computes Z[i] = A * X[i] + Y[i].
 
	-Uses dynamic memory allocation to store the vectors and scalar values.
 
	-Measures the execution time of the DAXPY computation in milliseconds.
 
	-Prints the first 10 elements of the resulting vector Z for correctness verification.

Assembly Function (DAXPYAsm.asm):

	-Performs the DAXPY operation in x86-64 assembly using SIMD floating-point instructions.
 
	-Iterates through the vectors and performs Z[i] = A * X[i] + Y[i] using mulsd (multiply scalar double) and addsd (add scalar double) instructions.
 
	-Uses functional scalar SIMD registers for efficient computation.
 
	-Handles input and output using registers and memory addressing, and loops through the vector elements.


Main Program (main_program.c):

	-Acts as the driver program that invokes the C and assembly implementations.
 
	-Allocates memory for the input vectors X, Y, and the result vector Z.
 
	-Randomly initializes the values of vectors X and Y, and the scalar A.
 
	-Measures and compares the execution time of the C and assembly DAXPY kernels.
 
	-Prints the first 10 elements of Z after both kernel executions for correctness check.
 

How to run program in CMD

nasm -f elf64 asmfunc.asm -o asmfunc.o

gcc -c daxpy.c -o daxpy.o -m64

gcc main_program.c daxpy.o asmfunc.o -o daxpy -m64

./daxpy


Performance Analysis
