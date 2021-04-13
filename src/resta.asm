segment .text
        global  calc_resta

calc_resta:
        enter   0,0               ; allocate room for sum on stack
        push    ebx               ; IMPORTANT!

        mov     eax, [ebp+8]   
        sub     eax, [ebp+12]

        JNO     no_carry
        mov     eax, 1
        mov     ebx, [ebp+16]
        mov     [ebx], eax

no_carry:
        pop     ebx               ; restore ebx
        leave
        ret