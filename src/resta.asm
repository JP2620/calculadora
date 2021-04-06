%include "./src/asm_io.inc"

segment .text
        global  calc_resta

calc_resta:
        enter   0,0               ; allocate room for sum on stack
        push    ebx               ; IMPORTANT!

        mov     eax, [ebp+8]   
        sub     eax, [ebp+12]
        mov     ebx, [ebp+16]
        mov     [ebx], eax

        pop     ebx               ; restore ebx
        leave
        ret

