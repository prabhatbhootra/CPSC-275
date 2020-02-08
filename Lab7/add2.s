	.file	"add2.c"
.LC0:
	.string	"%d plus %d equals %d\n"
	.globl	main

main:
	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	movl	$3, 16(%esp)
	movl	$2, 12(%esp)
	movl	$1, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk

	leave                           #last two lines process overhead
	ret



