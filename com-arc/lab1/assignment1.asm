.data

V1:	.word 5
V2:	.word 4

.text
.globl main

main:
	li	$t1, 10
	lw	$t2, V2
	add	$t3, $t1, $t2
	sw	$t3, V2
	li	$v0, 10
	syscall
