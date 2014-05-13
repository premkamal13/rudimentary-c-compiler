	.file	"in.c"
.globl _result
	.bss
	.align 4
_result:
	.space 4
.globl _size
	.data
	.align 4
_size:
	.long	10
.globl _a
	.align 32
_a:
	.long	10
	.long	20
	.long	30
	.long	40
	.long	50
	.long	60
	.long	70
	.long	80
	.long	90
	.long	100
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$1, 8(%esp)
	movl	_size, %eax
	movl	%eax, 12(%esp)
	movl	8(%esp), %eax
	imull	12(%esp), %eax
	movl	%eax, _result
	leave
	ret
