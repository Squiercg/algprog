L2: 	sll $t1, $a1, 2
	add $t1, $a0, $t1
	lw $t0, 0($t1)
	lw $t2, 4($t1)
	sw $t2, 0($t1)
	sw $t0, 4($t1)
	jr $ra

L1: 	addi $sp,$sp,-20
	sw $ra,16($sp)
	sw $s3,12($sp)
	sw $s2,8($sp)
	sw $s1,4($sp)
	sw $s0,0($sp)
	add $s2,$a0,$zero
	add $s3,$a1,$zero
	add $s0,$s0,$zero

loop1: 	slt $t0, $s0, $s3
	beq $t0, $zero, exit1
	addi $s1, $s0, -1

loop2: 	slti $t0, $s1, 0
	bne $t0, $zero, exit2
	sll $t1, $s1, 2
	add $t2, $s2, $t1
	lw $t3, 0($t2)
	lw $t4, 4($t2)
	slt $t0, $t4, $t3
	beq $t0, $zero, exit2
	add $a0, $s2, $zero
	add $a1, $s1, $zero
	jal L2
	addi $s1, $s1, -1
	j loop2

exit2: 	addi $s0, $s0, 1
	j loop1

exit1: 	lw $s0,0($sp)
	lw $s1,4($sp)
	lw $s2,8($sp)
	lw $s3,12($sp)
	lw $ra,16($sp)
	addi $sp,$sp,20
	jr $ra
main: