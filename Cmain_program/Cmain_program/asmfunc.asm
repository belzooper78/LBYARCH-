;assembly part 

section .data
msg db "Hello Wolrd",13,10,0

section .text
bits 64
default rel 

global asmhello
extern printf

asmhello:
	sub rsp, 8*5 ; caller
	lea rcx, [msg]
	call printf
	add rsp, 8*5
	ret