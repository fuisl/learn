.data

input_a:		.asciiz		"a = "
input_b:		.asciiz		"b = "
xec:			.asciiz		"/"

.text
.globl main

main:

input:
	li	$v0, 4
	la	$a0, input_a
	syscall
	li	$v0, 5
	syscall
	move	$s0, $v0		# $s0 = a
	
	li	$v0, 4
	la	$a0, input_b
	syscall
	li	$v0, 5
	syscall
	move	$s1, $v0		# $s1 = b
	
	beqz	$s0, aez		# A Equal Zero (aeq)
	
	neg 	$s1, $s1
	li	$v0, 1
	move	$a0, $s1
	syscall
	
	li	$v0, 4
	la	$a0, xec
	syscall
	
	li	$v0, 1
	move	$a0, $s0
	syscall
	
	j exit
	
aez:	
	beqz	$s1, inf_sol		# a = b = 0 -> ax+b=0 inf sol
	li	$v0, 4
	la	$a0, no_sol_msg
	syscall
	
	j exit


inf_sol:
	li	$v0, 4
	la	$a0, inf_sol_msg
	syscall
	
	j exit
	
exit:	
	li	$v0, 10
	syscall
.data

inf_sol_msg:		.asciiz		"ax + b = 0 has infinite solution\n"
no_sol_msg:		.asciiz		"ax + b = 0 has no solution\n"