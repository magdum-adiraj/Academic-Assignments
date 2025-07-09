section .data
	array db 25h,02h,13h,80h,55h

section .bss
	count resb 02
	result resb 10
	output resb 10

section .text
global _start
_start:

mov byte[count],05
mov bl,00
mov rsi,array
up:cmp bl,[rsi]
jge down
mov bl,[rsi]
down:inc rsi
dec byte[count]
jnz up
mov [result],bl

call disp

mov rax,01
mov rdi,01
mov rsi,output
mov rdi,02
syscall

mov rax,60
mov rdi,01
syscall

disp:
mov bl,[result]
mov byte[count],02
mov rsi,output
up1:rol bl,04
mov dl,bl
and dl,0fh
cmp dl,09h
jbe down1
add dl,07h
down1:add dl,30h
mov [rsi],dl
inc rsi
dec byte[count]
jnz up1
ret
