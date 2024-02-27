    .data
prompt:     .asciiz "Enter an integer N: "
result:     .asciiz "The sum is: "

    .text
    .globl main

main:
    # Display prompt
    li $v0, 4
    la $a0, prompt
    syscall
    
    # Read integer N from user input
    li $v0, 5
    syscall
    move $s0, $v0  # Store N in $s0

    # Initialize sum to 0
    li $t0, 0
    
    # Loop to calculate the sum
    loop:
        beqz $s0, end_loop   # If N is zero, exit loop
        add $t0, $t0, $s0    # Add N to sum
        subi $s0, $s0, 1      # Decrement N
        j loop
    
    # Exit loop
    end_loop:
    
    # Display the result
    li $v0, 4
    la $a0, result
    syscall
    
    # Print the sum
    li $v0, 1
    move $a0, $t0
    syscall
    
    # Exit
    li $v0, 10
    syscall
