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

![image](https://github.com/user-attachments/assets/60042093-24d8-486a-9e66-7ca6cfb5a377)

n = 2^20
1.2ms 
2.2ms
3.2ms
4.3ms
5.2ms
6.2ms
7.2ms
8.3ms
9.2ms
10.3ms
11.3ms
12.2ms
13.3ms
14.2ms
15.3ms
16.2ms
17.2ms
18.3ms
19.3ms
20.2ms
21.2ms
22.3ms
23.2ms
24.2ms
25.2ms
26.3ms
27.3ms
28.3ms
29.3ms
30.2ms
average = 2.433ms

n = 2^24
49ms
42ms
46ms
41ms
44ms
42ms
43ms
45ms
44ms
38ms
41ms
45ms
43ms
50ms
40ms
46ms
52ms
44ms
48ms
45ms
40ms
42ms
47ms
49ms
49ms
54ms
45ms
48ms
51ms
44ms
average = 45.23ms

n = 2^28
955ms
669ms
1085ms
1022ms
596ms
593ms
896ms
901ms
633ms
934ms
966ms
617ms
630ms
712ms
865ms
897ms
637ms
884ms
659ms
951ms
1123ms
789ms
928ms
612ms
848ms
740ms
974ms
998ms
597ms
838ms
average = 818.3 ms

