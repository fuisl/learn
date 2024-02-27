.data

var_a:		.word	0
msg:		.asciiz		"a = "
odd_msg:		.asciiz		"this number is odd."
even_msg:	.asciiz		"this number is even."

.text
.globl main

main:
	li	$v0, 4
	la	$a0, msg
	syscall
	
	li	$v0, 5
	syscall
	sw	$v0, var_a
	
	lw	$t1, var_a
	li	$t2, 2
	
	div	$t1, $t2
	
	mfhi	$t2
	beqz	$t2, even	# branch to even if a mod 2 = 0
	
	li	$v0, 4
	la	$a0, odd_msg
	syscall
	
	j exit
even:
	li	$v0, 4
	la	$a0, even_msg
	syscall
	
exit:
	li	$v0, 10
	syscall	