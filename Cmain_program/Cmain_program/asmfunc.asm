section .data
msg db "Hello World", 13, 10, 0 ; message for testing p

section .text
bits 64
default rel

global asmhello
global daxpy_asm
extern printf

; asmhello function (for testing purposes)
asmhello:
    sub rsp, 8*5           
    lea rcx, [msg]        
    call printf            
    add rsp, 8*5           
    ret

daxpy_asm:
    push rbp
    mov rbp, rsp
    push rbx
    push r12

    mov rdi, rdx        
    mov rsi, rcx        
    mov rdx, r8         
    mov r8, r9          
    mov r9, r10        

    xor rbx, rbx          

loop:
    cmp rbx, rdi           
    jge .end_loop           

    movsd xmm0, [rdx + rbx * 8] 
    movsd xmm1, [r8 + rbx * 8]  

    mulsd xmm0, rsi        
    addsd xmm0, xmm1      

    movsd [r9 + rbx * 8], xmm0 ; Store result in Z[i]

    inc rbx
    jmp loop

end_loop:
    pop r12
    pop rbx
    mov rsp, rbp
    pop rbp
    ret
