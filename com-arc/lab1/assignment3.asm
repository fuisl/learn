.data

arr:		.word	1, 2, 3, 4, 5

.text
.globl main

main:
	la	$t0, arr	# load address of array
	lw	$t1, 8($t0)	# load word from $t0 + 8 bits offset (2 bytes)
	lw	$t2, 16($t0)
	
	add	$s0, $t1, $t2
	
	li	$v0, 1
	move	$a0, $s0
	syscall
	
	li	$v0, 10
	syscall
	