.globl main 			#DOGLAS WENDLL SORGATTO
main:
	li $s4, 32		#guarda 32 em $s4
	li $v0, 5		#carrega comando de leitura de inteiro
	syscall			#efetua a leitura do valor informado pelo usu�rio
	
	add $s1, $v0, $zero	#guarda em $s1 o valor informado pelo usu�rio
	li $v0, 5		#carrega comando de leitura de inteiro
	syscall			#efetua a leitura do valor informado pelo usu�rio
	add $s2, $v0, $zero	#guarda em $s2 o valor informado pelo usu�rio
	
	bgez $s1, maior		#compara se $s1 � maior ou igual a zero, caso sim, vai para "maior"
	li $s3, 3		#guarda em $s3 o valor que ser� somado para dar o n�mero a ser impresso
loop:
	beq $s4, $s2, vai_2	#verifica se o segundo valor � igual a 32, caso sim, vai imprimir 5 + $s3
	slt $t0, $s4, $s2	#verifica se o segundo valor � menor que 32.
	beqz $t0, vai_4		#verifica se � menor que 32 (confirma��o)
	addi $a0, $s3, 3	#guarda o valor (1 ou 4) para impress�o
	li $v0, 1		#carrega comando de impress�o de inteiro
	syscall			#imprime
	j sai			#pula para encerrar o programa
	
vai_4:
	addi $a0, $s3, 3	#guarda o valor (3 ou 6) para impress�o
	li $v0, 1		#carrega comando de impress�o de inteiro
	syscall			#imprime
	j sai			#pula para encerrar o programa
	
vai_2:
	addi $a0, $s3, 2	#caso o n�mero seja 32, soma com o que est� em$s3
	li $v0, 1		#carrega comando de impress�o de inteiro
	syscall			#imprime
	j sai			#pula para encerrar o programa
	
maior: 
	li $s3, 0		#guarda em $s3 o valor que ser� somado para dar o n�mero a ser impresso
	j loop			#faz o loop

sai:
	li $v0, 10		#carrega comando de encerramento
	syscall			#encerra programa

	
	
