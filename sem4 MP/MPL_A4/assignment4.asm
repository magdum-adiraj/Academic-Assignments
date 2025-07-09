%macro rw 3
mov rax, %1
mov rdi, 01
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data
msg db 'Positive Numbers are: ', 10
len equ $-msg
msg2 db 'Negative Numbers are: ', 10
len2 equ $-msg2
arr db -01, -02, -10, -08, -05

section .bss
count resb 10
pos_count resb 10
neg_count resb 10
result resb 10
output resb 10

section .text
global _start
_start:

mov byte[pos_count], 00
mov byte[neg_count], 00
mov byte[count], 05
mov rsi, arr
up:
mov bh, [rsi]
add bh, 00
js l1
inc byte[pos_count]
jmp l2
l1:
inc byte[neg_count]
l2:
inc rsi
dec byte[count]
jnz up

rw 01, msg, len
mov bl, [pos_count]
mov [result], bl
call display
rw 01, output, 02

rw 01, msg2, len2
mov bl, [neg_count]
mov [result], bl
call display
rw 01, output, 02


mov rcx, 00h
mov ch, [neg_count]
mov cl, [pos_count]

end:

mov rax, 60
mov rdi, 00
syscall


; proc to display ascii values
display:
mov bl, [result]
mov byte[count], 02
mov rsi, output
digit:
rol bl, 04
mov dl, bl
and dl, 0fh
cmp dl, 09h
jbe down
add dl, 07h
down:
add dl, 30h
mov [rsi], dl
inc rsi
dec byte[count]
jnz digit
ret
