int i,j=10,k=30;
int a[5];
main()
{
	i = j + k;
}
/*int k;
int t,j,i;
main()
{
t = i+j;
t = i - j;
t = i * j;
t = i / j;
t = i % j;
t = i << j;
t = i >> j;
t = i | j;
t = i & j;
t = i ^ j;
}

	.file	"ins.c"
	.comm	_k, 4, 2
	.comm	_t, 4, 2
	.comm	_j, 4, 2
	.comm	_i, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	andl	$-16, %esp
	subl	$16, %esp
	call	___main

	=
	movl	_i, %eax
	movl	%eax, _t
	-
	movl	_i, %edx
	movl	_j, %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, _t
	*
	movl	_i, %edx
	movl	_j, %eax
	imull	%edx, %eax
	movl	%eax, _t
	/
	movl	_i, %eax
	movl	_j, %ebx
	movl	%ebx, 12(%esp)
	cltd
	idivl	12(%esp)
	movl	%eax, _t
	%
	movl	_i, %eax
	movl	_j, %ecx
	cltd
	idivl	%ecx
	movl	%edx, %eax
	movl	%eax, _t
	<<
	movl	_i, %edx
	movl	_j, %eax
	movl	%edx, %ebx
	movb	%al, %cl
	sall	%cl, %ebx
	movl	%ebx, %eax
	movl	%eax, _t
	>>
	movl	_i, %edx
	movl	_j, %eax
	movl	%edx, %ebx
	movb	%al, %cl
	sarl	%cl, %ebx
	movl	%ebx, %eax
	movl	%eax, _t
	|
	movl	_i, %edx
	movl	_j, %eax
	orl	%edx, %eax
	movl	%eax, _t
	&
	movl	_i, %edx
	movl	_j, %eax
	andl	%edx, %eax
	movl	%eax, _t
	^
	movl	_i, %edx
	movl	_j, %eax
	xorl	%edx, %eax
	movl	%eax, _t

	movl	-4(%ebp), %ebx
	leave
	ret


The generate_code function will have the following structure:
3.1-3.5 refer to the previous email with Sample-Output

This is a suggested structure only.
You are free to do any other way also, as long as you follow the
instructions of previous emails.

void generate_code( )
{
    // open the argv[3] in write mode

    fprintf(header of the ASM file: 3.1)

    for all entries in Quadruple table
    {
        switch (the Opcode column of the Quadruple table)
        {
            case '+': fprintf(instruction to MOV operand-1 of
quadruple-table into register).
                        fprintf(instruction to ADD the above register
with the operand-2 of the quadruple-table; register should get the
result)
                        fprintf(instruction to MOV the register to
the result-variable of the quadruple-table)
                        break;

            case '-': ....
            ...
            ...
            ...
            case IF: //  If-False t1 goto L2
                          // assume t1 is operand-1 in quadruple-table
                          // L2 is operand-2 of quadruple-table.
                          fprintf(instruction for CMP (cmp or cmpl)
operand-1 with 0 (dword 0 or $0)
                          fprintf(JZ operand-2 of quadruple-table)
                          break;

            case '<': // As discussed in class.
            // similar (with only op-code difference) for all 6: <=,
>, >=, ==, !=,
            ...
            ...
            ...

        }
    }
    fprintf(calling printf on size, result, a, as given in ASM file: 3.3)
    fprintf(footer of the ASM file: 3.4)
    fprintf(fixed portions of the data section of ASM file: 3.5-a)

    for all entries in the symbol table
    {
        switch (type of variable)
        {
            case INT: fprintf(variable name, .long (or .dd), init
value (0 if blank))
                          break;
            case CHAR: //Optional if time permits; i will test only on INT...
        }
    }
}


*/
