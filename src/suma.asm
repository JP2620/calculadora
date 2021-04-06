segment .text
        global  calc_sum

calc_sum:
        enter   12,0               ; allocate room for sum on stack
        push    ebx               ; IMPORTANT!

        mov     eax, [ebp+8]   
        add     eax, [ebp+12]
        mov     ebx, [ebp+16]
        mov     [ebx], eax

        pop     ebx               ; restore ebx
        leave
        ret




