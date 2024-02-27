.data
input_a:	.ascii 	"a = "
input_b:	.ascii	"b = "

var_a:		.word 0
var_b:		.word 0

.text
.globl main

main:
	li	$v0, 4		# Code 4 = print string
	la	$a0, input_a	# print string will print string in address store in $a0
	syscall
	
	li	$v0, 5
	syscall
	sw	$v0, var_a
	
	
	li	$v0, 4
	la	$a0, input_b
	syscall
	
	li	$v0, 5
	syscall		# return in $v0
	sw	$v0, var_b	# $t1 = b
	
	lw	$t0, var_a
	lw	$t1, var_b
	add	$s0, $t0, $t1
	#sw	$t2, var_b	# why not move? can we pass from register t
	
	li	$v0, 1
	move	$a0, $s0
	syscall
	
	li	$v0, 10
	syscall
	
.data
msg:	.asciiz		"Hello WOrld!\n"
