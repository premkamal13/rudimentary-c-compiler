; (3.1) Header of the Text section
extern	_printf
SECTION .text
global _main
_main:
	push    ebp
	mov     ebp, esp
	and	esp, -16
	
; (3.2) THIS IS *YOUR* WORK
; Convert the TACs into Assembly instructions
	mov	[i], dword 1

	mov 	eax, [size]
	mov	[j], eax

	mov 	eax, [i] 
	add	eax, [j]
	mov 	[t_0000001], eax

	mov	eax, [t_0000001]
	mov	[result], eax

	; (3.3): Print the result, size, array a
	mov	eax, [result]
	mov	[4+esp], eax
	mov 	eax, printtext1
	mov 	[esp], eax
	call    _printf

	mov	eax, [size]
	mov	[4+esp], eax
	mov 	eax, printtext2
	mov 	[esp], eax
	call    _printf

	mov 	eax, printtext3
	mov 	[esp], eax
	mov	ecx, 0
print_a:
	cmp	ecx, [size]
	jz	exit
	mov	eax, [ecx*4 + a]
	mov	[4+esp], eax
	mov	[temp_count], ecx
	call    _printf
	mov 	ecx, [temp_count]
	add	ecx, 1
	jmp	print_a
exit:

	; (3.4) Footer of the text section
	mov     esp, ebp
	pop     ebp
	ret
	
; (3.5-a) Hardcoded data section
SECTION .data
printtext1: db "result = %d", 10, 0
printtext2: db "size = %d", 10, 0
printtext3: db "%d, ", 0
temp_count: dd 0

; (3.5-b) variable declarations from *YOUR* Symbol table
result: dd 0
size: dd 10
a: dd 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
i: dd 0
j: dd 0
t_0000001: dd 0
