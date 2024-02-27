.data
S1: .ascii "wxy\n"
sum: .word 0x67892
i: .word 0
t: .word 10

.text
	lw $s0, sum
	lw $s1, i
	lw $s2, t
Loop:
	add $s0, $s1, $s2
	addi $s1, $s1, 1
	bne $s1, $s2, Loop
	sw $s0, sum
	j Loop
end:
	li $a0, 10
	syscall
