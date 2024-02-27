.data
prompt:		.asciiz		"N = "
space:		.asciiz		" "

.text
.globl main
main:
	li	$v0, 4
	la	$a0, prompt
	syscall
	
	li	$v0, 5
	syscall
	move	$s0, $v0	# set s0 = N

	li	$s1, 1		# init first = 1
	li	$s2, 1		# init second = 1
	beqz	$s0, exit

print_first:
	li	$v0, 1
	move	$a0, $s1
	syscall
	
	beq	$s0, $s1, exit  # if N = 1, exit
	li	$v0, 4
	la	$a0, space
	syscall

print_second:
	li	$v0, 1
	move	$a0, $s2
	syscall
	
	add	$s1, $s1, $s2	# s1 = s1 + s2 = 2
	beq	$s0, $s1, exit	# if N = 2 --> exit
	li	$v0, 4
	la	$a0, space
	syscall


	# start if N > 2
	li	$s3, 2		# init i = 2
loop:
	beq	$s3, $s0, end_loop
	
	# print next ele
	li	$v0, 1
	move	$a0, $s1
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	
	# update ele
	move	$t0, $s1	# t0 = temp
	add	$s1, $s1, $s2
	move	$s2, $t0
	
	# update s3
	addi	$s3, $s3, 1
	
	j	loop
end_loop:

exit:
	li	$v0, 10
	syscall