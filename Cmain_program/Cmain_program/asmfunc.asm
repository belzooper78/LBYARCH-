section .data
section .text
bits 64
default rel
global daxpy_asm


daxpy_asm:
    push rbx                
    push r12                

    sub rsp, 8             

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

    movsd [r9 + rbx * 8], xmm0 

    inc rbx
    jmp loop

end_loop:
    add rsp, 8             
    pop r12
    pop rbx
    ret
