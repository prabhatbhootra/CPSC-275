	.file	"fact.s"
.LC0:
	.string	"Enter an integer\n"
.LC1:
	.string "%d"
.LC2:
	.string "Please enter an integer greater than 0\n"
.LC3:
	.string "Factorial is %d\n"

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
	movl	28(%esp), %edx
	movl	%edx, 16(%esp)
	jmp	.L2

.L3:
	movl	$.LC2, (%esp)
	call	puts
.L2:
	cmpl	$1, 16(%esp)
	je	.L1
	decl	16(%esp)
	movl	16(%esp), %eax
	imul	28(%esp), %eax
	movl	%eax, 28(%esp) 
	jmp	.L2
.L1:
	movl	28(%esp), %edx
 	movl	%edx, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf

	leave                           #last two lines process overhead
	ret



