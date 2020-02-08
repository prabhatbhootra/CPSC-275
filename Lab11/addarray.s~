	.file	"addarray.s"

	.type	addarray, @function
addarray:

	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	movl	16(%esp), %ecx
	movl	20(%esp), %ebx
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	movl	$0, %eax
.L3:
	movl	(%ebx,%eax,4), %edx
	addl	(%esi,%eax,4), %edx
	movl	%edx, (%edi,%eax,4)
	addl	$1, %eax
	cmpl	%ecx, %eax
	jne	.L3
	
	leave
	ret

