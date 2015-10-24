.globl main 			#DOGLAS WENDLL SORGATTO
main:
	li $s4, 32		#guarda 32 em $s4
	li $v0, 5		#carrega comando de leitura de inteiro
	syscall			#efetua a leitura do valor informado pelo usuário
	
	add $s1, $v0, $zero	#guarda em $s1 o valor informado pelo usuário
	li $v0, 5		#carrega comando de leitura de inteiro
	syscall			#efetua a leitura do valor informado pelo usuário
	add $s2, $v0, $zero	#guarda em $s2 o valor informado pelo usuário
	
	bgez $s1, maior		#compara se $s1 é maior ou igual a zero, caso sim, vai para "maior"
	li $s3, 3		#guarda em $s3 o valor que será somado para dar o número a ser impresso
loop:
	beq $s4, $s2, vai_2	#verifica se o segundo valor é igual a 32, caso sim, vai imprimir 5 + $s3
	slt $t0, $s4, $s2	#verifica se o segundo valor é menor que 32.
	beqz $t0, vai_4		#verifica se é menor que 32 (confirmação)
	addi $a0, $s3, 3	#guarda o valor (1 ou 4) para impressão
	li $v0, 1		#carrega comando de impressão de inteiro
	syscall			#imprime
	j sai			#pula para encerrar o programa
	
vai_4:
	addi $a0, $s3, 3	#guarda o valor (3 ou 6) para impressão
	li $v0, 1		#carrega comando de impressão de inteiro
	syscall			#imprime
	j sai			#pula para encerrar o programa
	
vai_2:
	addi $a0, $s3, 2	#caso o número seja 32, soma com o que está em$s3
	li $v0, 1		#carrega comando de impressão de inteiro
	syscall			#imprime
	j sai			#pula para encerrar o programa
	
maior: 
	li $s3, 0		#guarda em $s3 o valor que será somado para dar o número a ser impresso
	j loop			#faz o loop

sai:
	li $v0, 10		#carrega comando de encerramento
	syscall			#encerra programa

	
	
