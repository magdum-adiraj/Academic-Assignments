%macro write 3
	mov rax,%1
	mov rdi,01
	mov rsi,%2
	mov rdx,%3
	syscall
%endmacro

section .data

result db 0
stringl db 10,"Menu :",15," 1)Addition ",15," 2)Subtraction ",15,"3)Multiplication ",15," 4)Division ",15
lenl equ $-stringl
stringx db "     "
lenx equ $-stringx
stringm db "Enter the choice :"
lenm equ $-stringm
stringn db "Result is: "
lenn equ $-stringn
numbrp db 8
numbrq db 4
cnt db 00h


section .bss
AscArray resb 2
choice resb 1


global _start
section .text
_start:

menu:	
	write 01,stringl,lenl
	write 01,stringx,lenx
	write 01,stringm,lenm
	write 00,choice,2
	sub byte[choice],30h
	
	cmp byte[choice],01h
	jz addition_op
	cmp byte[choice],02h
	jz substraction_op
	cmp byte[choice],03h
	jz multiplication_op
	cmp byte[choice],04h
	jz division_op
	jmp exit
	
addition_op:
	mov al,byte[numbrp]
	add al,byte[numbrq]
	mov byte[result],al
	jmp display



substraction_op:
	mov al,byte[numbrp]
	sub al,byte[numbrq]
	mov byte[result],al
	jmp display


multiplication_op:
	mov al,byte[numbrp]
	mul byte[numbrq]
	mov byte[result],al
	jmp display
	


division_op:
	mov al,byte[numbrp]
	div byte[numbrq]
	mov byte[result],al
	jmp display
	
display:  
	mov byte[cnt],02
	mov rsi,AscArray
	mov bl,byte[result]

again: 
	rol bl,04
	mov al,bl
	and al,0Fh
	cmp al,09h
	jbe next
	add al,07h

next:   add al,30h
	mov [rsi],al
	inc rsi
	dec byte[cnt]
	jnz again
	
	write 01,stringn,lenn
	write 01,AscArray,02h
	jmp menu
exit:	
	mov rax,60
	mov rdi,00
	syscall
