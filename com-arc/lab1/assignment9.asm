.data
arr1:		.space		20
arr2:		.space		20
arr3:		.space		20

.text
.globl	main
main:
	# input
	li	$v0, 8
	li	$a1, 20		# set length = 20
	la	$a0, arr1
	syscall
	
	li	$v0, 8
	li	$a1, 20		# set length = 20
	la	$a0, arr2
	syscall

	#copy
	la	$t1, arr1
	la	$t2, arr2
	la	$t3, arr3
	li	$t0, 0		# i = 0
	
init:
	move	$t5, $t1	# set t5 to address of t1
loop:
	beq	$t0, 20, exit_loop  # if reached 20 character in array 3
	lb	$t4, 0($t5)	# get element i
	beqz	$t4, check	# if end of string -> check
	sb	$t4, 0($t3)
	
	#update
	addi	$t0, $t0, 1
	addi	$t5, $t5, 1
	addi	$t3, $t3, 1
	
	j	loop
check:
	
	beq	$t1, $t2, exit_loop	# if already switching to arr2 -> exit
	move	$t1, $t2	# set address t1 = t2
	j	init

exit_loop:
	
	#print
	li	$v0, 4
	la	$a0, arr3
	syscall
exit:
	li	$v0, 10
	syscall
