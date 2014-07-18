.text			#DOGLAS WENDLL SORGATTO

main:
	li $v0, 5   		#leitura de x (BASE)
	syscall
	addi $s0, $v0, 0	#Guarda base em s0
	li $v0,5   		#leitura de y (Expoente)
	syscall
	addi $s1, $v0, 0	#Guarda expoente em s1
	addi $s2, $s0, 0	#copia a base para s2
	li $t0, 1		#Guarda 1 em t0 (condição de parada)
while:
  	beq $t0, $s1, fim	#compara se o expoente atingiu a condição de parada
  	mul $s2, $s2, $s0	#multiplica a base por si mesma
  	addi $t0, $t0, 1	#incrementa a condição de parada
  	j while			#faz a volta até atingir a condição de parada

fim:	add $a0, $s2, $zero	#transfere o resultado para a0 (condição de impressão)
	li $v0, 1		#Carrega argumento para impressão de inteiro
	syscall

	li $v0,	10		#comando de encerramento
	syscall