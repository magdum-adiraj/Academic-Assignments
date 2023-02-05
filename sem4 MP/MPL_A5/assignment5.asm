%macro rw 3
mov rax, %1
mov rdi, 01
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data
	array db 01,02,03,04,05
	count db 05
section .bss
	array2 resb 10

section .text
	global _start
	_start:
	
mov rsi,array
mov rdi,array2
mov rcx,05
cld
rep movsb
mov rdi,array2
up:
rw 01,rdi,01
inc rdi
dec count
jnz up

mov rax, 60
mov rdi, 00
syscall


