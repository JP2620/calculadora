%include "./src/asm_io.inc"

segment .text
        global  calc_sum

calc_sum:
        enter   12,0               ; allocate room for sum on stack
        push    ebx               ; IMPORTANT!

        dump_stack 1, 2, 4
        mov     eax, [ebp+8]   
        add     eax, [ebp+12]
        mov     ebx, [ebp+16]
        mov     [ebx], eax
        dump_regs 1

        pop     ebx               ; restore ebx
        leave
        ret




