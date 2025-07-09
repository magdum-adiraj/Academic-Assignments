section .data
	msg db 'Enter the numbers',10
	len equ $-msg
	msg1 db 'The numbers are',10
	len1 equ $-msg1

section .bss
	array resb 100
	count resb 05

%macro print 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .text
global _start
_start:

;to input numbers in array
print 01,01,msg,len
mov byte[count],05
mov rbx,array
up:print 00,00,rbx,17
add rbx,17
dec byte[count]
jnz up

;to output the numbers in array
print 01,01,msg1,len1
mov byte[count],05
mov rbx,array
up1:print 01,01,rbx,17
add rbx,17
dec byte[count]
jnz up1

;exit system call
mov rax,60
mov rdi,01
syscall
