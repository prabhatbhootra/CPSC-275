	.file	"collatz.s"
        .text
	.globl	collatz
	.type	collatz, @function

collatz:
        pushl	%ebp                    #first four lines process overhead
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp

	movl 8(%ebp), %esi              #store number is register esi
        movl $2, %ecx			#store 2 in register ecx
        movl $0, %edi			#store 0 in register edi
        movl $3, %ebx			#store 3 in register ebx
        cmpl $1, %esi                   #if number is equal to one, return k = 0 by jumping to .L1
        je   .L1

.L3:
        movl %esi, %edx			#copy number to edx to store high order bits
        movl %edx, %eax			#copy number to eax to store low order bits
        sarl $31, %edx			#sign extend high order bits
	idivl %ecx                      #Find quotient and remainder of number when divided by 2
        cmpl $0, %edx			#Check if remained is 0
        je .L2				#If remainder is 0, jump to .L2 to increment k
        imul %ebx, %esi                 #If remainder is not 0, multiply original number by 3 
        incl %esi			#Then add 1 to number after multiplying by 3
        incl %edi                       #increment k
        cmpl $1, %esi			#Check if number is now equal to 1
        je .L1				#if number is equal to one, return k = 0 by jumping to .L1
        jmp .L3				#else repeat the process for the new number
	
.L2:
        movl %eax, %esi                 #Update value of esi to store new number
        incl %edi                       #increment k
        cmpl $1, %esi			#Check if the value of the new number is 1
        je   .L1			#If the number is 1, jump to .L1 and return the stopping time
        jmp  .L3 			#else repeat the process for the new value
 
.L1:
	movl %edi, %eax                 #When number is equal to 1, return the stopping time

        leave
        ret
