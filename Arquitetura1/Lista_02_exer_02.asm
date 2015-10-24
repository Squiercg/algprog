.globl main		#DOGLAS WENDLL SORGATTO
main:
	li $s0, 30	#carrega 30 (multiplicador)
	li $s1, 23	#carrega 23 (multiplicando)
	li $s5, 0	#carrega 0 (resultado)
	
loop:	
	beq $s0, $zero, sai	#compara o multiplicador com 0 (condição de parada)
	add $s5, $s5, $s1	#soma 23 ao resultado do registrador $s5
	addi $s0, $s0, -1	#subtrai um do multiplicador
	j loop			#retorna para o loop
	
sai:
	addi $a0, $s5, 0	#carrega o resultado para impressão
	li $v0, 1		#carrega comando de impressão
	syscall			#imprime resultado
	li $v0, 10		#carrega comando de encerramento
	syscall			#encerra programa