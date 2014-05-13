// (3.1) Header of the Text section
.text
.globl _main
_main: 
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp

	// (3.2) THIS IS *YOUR* WORK
	// Convert the TACs into Assembly instructions
	movl	$1, i
	
	movl	size, %eax
	movl	%eax, j

	movl	i, %eax
	addl	j, %eax
	movl	%eax, t_0000001

	movl	t_0000001, %eax
	movl 	%eax, result

	// (3.3): Print the result, size, array a
	movl	result, %eax
	movl	%eax, 4(%esp)
	movl	$printtext1, %eax
	movl	%eax, (%esp)
	call	_printf

	movl	size, %eax
	movl	%eax, 4(%esp)
	movl	$printtext2, %eax
	movl	%eax, (%esp)
	call	_printf

	movl	$printtext3, %eax
	movl	%eax, (%esp)
	movl	$0, %ecx
print_a:
	cmpl	%ecx, size
	jz 	exit
	movl	a(,%ecx,4), %eax
	movl	%eax, 4(%esp)
	movl	%ecx, temp_count
	call	_printf
	movl	temp_count, %ecx
	addl	$1, %ecx
	jmp 	print_a
exit:

	// (3.4) Footer of the text section
	movl %ebp, %esp
	popl %ebp
	ret

// (3.5-a) Hardcoded data section
.data
printtext1: .ascii "result = %d\n\0"
printtext2: .ascii "size = %d\n\0"
printtext3: .ascii "%d, \0"
temp_count: .long 0

// (3.5-b) variable declarations from *YOUR* Symbol table
result: .long 0
size: .long 10
a: .long 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
i: .long 0
j: .long 0
t_0000001: .long 0
