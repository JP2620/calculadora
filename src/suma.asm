segment .text
        global  calc_sum

calc_sum:
        enter   0,0               ; allocate room for sum on stack
        push    ebx               ; IMPORTANT!

        mov     eax, [ebp+8]   
        add     eax, [ebp+12]

        pop     ebx               ; restore ebx
        leave
        ret




