//modex.s

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
	movl 	%esi, (%esp)
	movl	24(%esp), %edi
	movl 	%edi, 4(%esp)
	movl	20(%esp), %ebx
	movl 	%ebx, 8(%esp)
	call	modex

	leave                           #last two lines process overhead
	ret
	

modex:
	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	
	movl	
	call	mypow
	movl	$0, 16(%esp)
		
	leave                           #last two lines process overhead
	ret

mypow:
	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	










