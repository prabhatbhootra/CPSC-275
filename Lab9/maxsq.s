//maxsq.s


.LC1:
	.string "%d"
.LC3:
	.string "The largest square: %d\n"

	.globl	main

main:
	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	movl	$.LC1, (%esp)
	leal	28(%esp), %eax
	movl    %eax, 4(%esp)
        call	scanf
	

	movl	$.LC1, (%esp)
	leal	24(%esp), %ebx
	movl    %ebx, 4(%esp)
        call	scanf
	

	movl	$.LC1, (%esp)
	leal	20(%esp), %ecx
	movl    %ecx, 4(%esp)
        call	scanf
	
	movl	28(%esp), %esi
	movl 	%esi, 4(%esp)
	movl	24(%esp), %edi
	movl 	%edi, 8(%esp)
	movl	20(%esp), %ebx
	movl 	%ebx, 12(%esp)
	call	max_square

	leave                           #last two lines process overhead
	ret
	

max_square:
	
	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	movl	$0, 16(%esp)

	movl	12(%ebp), %edx
	imul	12(%ebp), %edx
	movl	16(%ebp), %esi
	imul	16(%ebp), %esi
	movl	20(%ebp), %ecx
	imul	20(%ebp), %ecx

	cmpl	16(%esp), %edx
	jg	.L4
	
.L4:	
	movl	%edx, 16(%esp)
	cmpl	16(%esp), %esi
	jg	.L3
	cmpl	16(%esp), %ecx
	jg	.L2
	jmp     .L1
.L3:	
	movl	%esi, 16(%esp)
	cmpl	16(%esp), %ecx
	jg	.L2
	jmp     .L1
.L2:
	movl	%ecx, 16(%esp)
	jmp     .L1
.L1:
	movl	16(%esp), %edi
	movl	%edi, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	leave                           #last two lines process overhead
	ret

