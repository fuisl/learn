.data

arr:		.space		40
space:		.asciiz		" "

.text
.globl main

main:

	li	$s0, 10		# hold n = 10
	li	$s1, 0		# init i = 0
	la	$a0, arr	# load address of array s2
loop:
	beq	$s0, $s1, end_loop
	
	#call input
	li	$v0, 5
	syscall		# input in v0
	
	#calculcate index (byte)
	sw	$v0, 0($a0)
	addi	$a0, $a0, 4
	
	#increase s1
	addi	$s1, $s1, 1
	
	j	loop
end_loop:


	li	$s1, 0
	la	$a1, arr
loop_print:
	beq	$s1, 10, end_loop_print
	li	$v0, 1
	lw	$a0, 0($a1)
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	
	# update next index
	addi	$a1, $a1, 4
	
	#increase s1
	addi	$s1, $s1, 1
	j	loop_print
end_loop_print:
	
	la	$t1, arr
	li	$s1, 0
	la	$a1, 36($t1)	# go to last element of array
print_reverse_loop:
	beq	$s1, 10, end_reverse_loop
	li	$v0, 1
	lw	$a0, 0($a1)
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	
	# update in reverse order
	subi	$a1, $a1, 4
	
	# update i
	addi	$s1, $s1, 1
	
	j	print_reverse_loop
end_reverse_loop:

	li	$s2, 0		#init s2 = sum = 0
	la	$a0, arr
	li	$s1, 0		#init i = 0
sum_loop:
	beq	$s1, 10, end_sum_loop
	lw	$t1, 0($a0)
	add	$s2, $s2, $t1
	
	addi	$a0, $a0, 4	#go to next element
	addi	$s1, $s1, 1	# update i
	j	sum_loop
end_sum_loop:

	# print sum
	li	$v0, 1
	move	$a0, $s2
	syscall

exit:
	li	$v0, 10
	syscall
