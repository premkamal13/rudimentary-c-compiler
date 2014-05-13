	.file	"ins.c"
	.comm	_i, 4, 2
	.globl	_j
	.data
	.align 4
_j:
	.long	10
	.globl	_k
	.align 4
_k:
	.long	30
	.comm	_a, 20, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	call	___main
	
	movl	_j, %edx
	movl	_k, %eax
	addl	%edx, %eax
	movl	%eax, _i
	
	leave
	ret
