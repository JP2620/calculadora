segment .text
        global  calc_sum

calc_sum:
        enter   12,0               ; allocate room for sum on stack
        push    ebx               ; IMPORTANT!

        mov     dword eax, [ebp+8]   
        add     dword eax, [ebp+12]
        mov     dword [ebp+16], eax

        pop     ebx               ; restore ebx
        leave
        ret




