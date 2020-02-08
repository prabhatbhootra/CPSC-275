	.file	"divmod.s"
.LC0:
	.string	"Quotient followed by Modulus: %d and %d\n"
	.globl	main

main:
	pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
        
        movl $0x33, 28(%esp)
        movl $0x14, 24(%esp)
        movl 28(%esp), %edx
        movl %edx, %eax
        sarl $31, %edx
        idivl 24(%esp)

        movl %eax, 8(%esp)
        movl %edx, 4(%esp)
        movl $.LC0, (%esp)
        call printf
        

	leave                           #last two lines process overhead
	ret

