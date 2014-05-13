	.file	"in.c"
.globl _result
	.data
	.align 4
_result:
	.long	1
.globl _i
	.align 4
_i:
	.long	10
.globl _j
	.align 4
_j:
	.long	10
.globl _k
	.align 4
_k:
	.long	10
	.comm	_a, 400	 # 400
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	call	___main
	
	movl	_j, %eax
	movl	_a(,%eax,4), %edx
	movl	_i, %eax
	movl	_a(,%eax,4), %eax
	cmpl	%eax, %edx
	jge	L4
	movl	_j, %eax
	movl	%eax, _i
L4:
	
	leave
	ret
