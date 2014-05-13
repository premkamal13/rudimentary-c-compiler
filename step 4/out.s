.text
.globl _main
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp

	movl	$0, %eax
	movl	%eax, i
L_000001:
	movl	size, %edx
	movl	$1, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_000001
	movl	i, %edx
	movl	t_000001, %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, t_000002
	movl	$0, %edx
	movl	t_000002, %eax
	cmpl	%eax,%edx
	je L_000002
	movl	i, %edx
	movl	$1, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_000003
	movl	t_000003, %eax
	movl	%eax, j
L_000003:
	movl	j, %edx
	movl	size, %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, t_000004
	movl	$0, %edx
	movl	t_000004, %eax
	cmpl	%eax,%edx
	je L_000004
	movl	$0, %eax
	movl	%eax, t_000005
	movl	j, %eax
	movl	%eax, t_000006
	movl	t_000005, %edx
	movl	t_000006, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_000005
	movl	t_000005, %edx
	movl	$4, %eax
	imull	%edx, %eax
	movl	%eax, t_000005
	movl	$0, %eax
	movl	%eax, t_000007
	movl	i, %eax
	movl	%eax, t_000008
	movl	t_000007, %edx
	movl	t_000008, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_000007
	movl	t_000007, %edx
	movl	$4, %eax
	imull	%edx, %eax
	movl	%eax, t_000007
	movl	t_000005, %eax
	movl	a(,%eax,1), %eax
	movl	%eax, t_000009
	movl	t_000007, %eax
	movl	a(,%eax,1), %eax
	movl	%eax, t_0000010
	movl	t_000009, %edx
	movl	t_0000010, %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, t_0000011
	movl	$0, %edx
	movl	t_0000011, %eax
	cmpl	%eax,%edx
	je L_000005
	movl	$0, %eax
	movl	%eax, t_0000012
	movl	i, %eax
	movl	%eax, t_0000013
	movl	t_0000012, %edx
	movl	t_0000013, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_0000012
	movl	t_0000012, %edx
	movl	$4, %eax
	imull	%edx, %eax
	movl	%eax, t_0000012
	movl	t_0000012, %eax
	movl	a(,%eax,1), %eax
	movl	%eax, t_0000014
	movl	t_0000014, %eax
	movl	%eax, temp
	movl	$0, %eax
	movl	%eax, t_0000015
	movl	i, %eax
	movl	%eax, t_0000016
	movl	t_0000015, %edx
	movl	t_0000016, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_0000015
	movl	t_0000015, %edx
	movl	$4, %eax
	imull	%edx, %eax
	movl	%eax, t_0000015
	movl	$0, %eax
	movl	%eax, t_0000017
	movl	j, %eax
	movl	%eax, t_0000018
	movl	t_0000017, %edx
	movl	t_0000018, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_0000017
	movl	t_0000017, %edx
	movl	$4, %eax
	imull	%edx, %eax
	movl	%eax, t_0000017
	movl	t_0000017, %eax
	movl	a(,%eax,1), %eax
	movl	%eax, t_0000019
	movl	t_0000015, %eax
	movl	t_0000019, %edx
	movl	%edx, a(,%eax,1)
	movl	$0, %eax
	movl	%eax, t_0000020
	movl	j, %eax
	movl	%eax, t_0000021
	movl	t_0000020, %edx
	movl	t_0000021, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_0000020
	movl	t_0000020, %edx
	movl	$4, %eax
	imull	%edx, %eax
	movl	%eax, t_0000020
	movl	t_0000020, %eax
	movl	temp, %edx
	movl	%edx, a(,%eax,1)
L_000005:
	movl	j, %edx
	movl	$1, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_0000022
	movl	t_0000022, %eax
	movl	%eax, j
	jmp L_000003
L_000004:
	movl	i, %edx
	movl	$1, %eax
	movl	%edx, %ecx
	addl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, t_0000023
	movl	t_0000023, %eax
	movl	%eax, i
	jmp L_000001
L_000002:
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
	jmp	print_a
exit:
	movl %ebp, %esp
	popl %ebp
	ret

.data
printtext1: .ascii "result = %d\n\0"
printtext2: .ascii "size = %d\n\0"
printtext3: .ascii "%d, \0"
temp_count: .long 0

result: .long  0
size: .long  10
a: .long 5, 1, 3, 9, 8, 4, 10, 2, 6, 7
i: .long 0
j: .long 0
temp: .long 0
t_000001: .long 0
t_000002: .long 0
t_000003: .long 0
t_000004: .long 0
t_000005: .long 0
t_000006: .long 0
t_000007: .long 0
t_000008: .long 0
t_000009: .long 0
t_0000010: .long 0
t_0000011: .long 0
t_0000012: .long 0
t_0000013: .long 0
t_0000014: .long 0
t_0000015: .long 0
t_0000016: .long 0
t_0000017: .long 0
t_0000018: .long 0
t_0000019: .long 0
t_0000020: .long 0
t_0000021: .long 0
t_0000022: .long 0
t_0000023: .long 0
