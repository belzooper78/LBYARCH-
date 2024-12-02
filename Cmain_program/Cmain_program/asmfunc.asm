section .data
section .text
bits 64
default rel
global daxpy_asm

daxpy_asm:
    push rbx
    push r12

    sub rsp, 8               ; Align the stack (ensure 16-byte alignment)
    
    mov r12, rdi             ; r12 = N (number of elements)
    mov rdi, rsi             ; rdi = scalar a
    mov rsi, rdx             ; rsi = pointer to array X
    mov rdx, rcx             ; rdx = pointer to array Y
    mov rcx, r8              ; rcx = pointer to array Z

    xor rbx, rbx             ; rbx = loop index (i = 0)

.loop:
    cmp rbx, r12             ; Compare i with N
    jge .end_loop            ; Exit if i >= N
    
    movsd xmm0, [rsi + rbx * 8] ; Load X[i] into xmm0
    movsd xmm1, [rdx + rbx * 8] ; Load Y[i] into xmm1
    
    mulsd xmm0, xmm0         ; xmm0 = a * X[i]
    addsd xmm0, xmm1         ; xmm0 = (a * X[i]) + Y[i]
    
    movsd [rcx + rbx * 8], xmm0 ; Store the result in Z[i]
    
    inc rbx                  ; i++
    jmp .loop

.end_loop:
    add rsp, 8               ; Restore stack alignment
    pop r12
    pop rbx
    ret
