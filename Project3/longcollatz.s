	.file	"longcollatz.s"
	.text
	.globl	longcollatz
	.type	longcollatz, @function
.LC0:
        .string "%u,   %u\n"

longcollatz:

        pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	movl    8(%ebp), %eax
        movl 	$2, %ecx
        movl 	$0, %edi
        movl 	$3, %ebx
        
.L5:
        cmpl    (%eax), $0
        je	.L4
     
.L3:
	
	   

.L4:
   	cmpl    4(%eax), $1
        je	.L1
        jmp	.L3
	

.L1:        
	leave
	ret

