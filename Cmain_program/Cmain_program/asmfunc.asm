section .data
section .text
bits 64
default rel
global daxpy_asm

daxpy_asm:
    push rbx
    push r12

    sub rsp, 8               
    
    mov r12, rdi            
    mov rdi, rsi            
    mov rsi, rdx          
    mov rdx, rcx            
    mov rcx, r8              

    xor rbx, rbx            

.loop:
    cmp rbx, r12             
    jge .end_loop            
    
    movsd xmm0, [rsi + rbx * 8] 
    movsd xmm1, [rdx + rbx * 8] 
    
    mulsd xmm0, xmm0        
    addsd xmm0, xmm1         
    
    movsd [rcx + rbx * 8], xmm0 
    
    inc rbx                  
    jmp .loop

.end_loop:
    add rsp, 8              
    pop r12
    pop rbx
    ret
