	.file	"fibassy.s"
.LC0:
	.string	"Enter an integer\n"
.LC1:
	.string "%d, "
.LC2:
	.string "Please enter an integer greater than 0\n"

	.globl	main

main:
	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	movl	$.LC0, (%esp)
	call    puts
 	movl	$.LC1, (%esp)
        
	leal	28(%esp), %eax
	movl    %eax, 4(%esp)
        call	__isoc99_scanf

	cmpl	$0, 28(%esp)
	js	.L3
	movl	$0, 24(%esp)
	movl	$1, 20(%esp)
	movl	$0, 16(%esp)
	movl    $2, 8(%esp)

	movl	24(%esp), %esi
	movl	%esi, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	20(%esp), %esi
	movl	%esi, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	jmp	.L2

.L3:
	movl	$.LC2, (%esp)
	call	puts
.L2:
	movl	20(%esp), %esi
	addl	%esi, 16(%esp)
	movl	24(%esp), %esi
	addl	%esi, 16(%esp)

	movl	16(%esp), %ebx
	movl	%ebx, 4(%esp)
	movl	$.LC1, (%esp)
	call 	printf

	movl	20(%esp), %esi
	movl	%esi, 24(%esp)
	movl	16(%esi), %esi
	movl	%esi, 20(%esi)

	incl	8(%esp)
	movl	8(%esp), %ebx
	cmpl	%ebx, 28(%esp)
	jne 	.L2


	leave                           #last two lines process overhead
	ret

