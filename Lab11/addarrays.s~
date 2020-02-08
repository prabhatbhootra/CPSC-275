	.file	"addarrays.c"
	.text
	.globl	addarray
	.type	addarray, @function
addarray:
.LFB24:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %ecx
	movl	20(%esp), %ebx
	movl	24(%esp), %esi
	movl	28(%esp), %edi
	testl	%ecx, %ecx
	jle	.L1
	movl	$0, %eax
.L3:
	movl	(%ebx,%eax,4), %edx
	addl	(%esi,%eax,4), %edx
	movl	%edx, (%edi,%eax,4)
	addl	$1, %eax
	cmpl	%ecx, %eax
	jne	.L3
.L1:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE24:
	.size	addarray, .-addarray
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
