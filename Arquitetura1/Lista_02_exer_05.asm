.data 				#DOGLAS WENDLL SORGATTO
	space: .asciiz " "
	
.text
.globl main
main: 	
	li $s0, 20		#quandidade de n�meros a serem lidos
	addi $sp, $sp, -80	#reserva 20 posi��es na pilha
	add $s1, $s0, $zero	#copia o tamanho do vetor para outro registrador
recebe:
	beqz $s0, imprime	#compara se todos os n�meros foram recebidos
	li $v0, 5		#comando para leitura de entrada
	syscall			#recebe entrada
	sw $v0, 0($sp)		#guarda entrada na pilha
	addi $sp, $sp, 4	#vai para o pr�ximo endere�o da pilha
	addi $s0, $s0, -1	#diminui o contador em uma unidade
	j recebe		#retorna para compara��o e recebimento de n�meros
imprime:
	addi $sp, $sp, -4	#diminui uma posi��o na pilha
	beqz $s1, sai		#compara se contador local est� zerado
	lw $a0, 0($sp)		#carrega para impress�o o valor do fim da pilha
	li $v0, 1		#carrega comado de impress�o
	syscall			#imprime
	li $v0, 4		#carrega comando de impress�o
	la $a0, space		#carrega informa��o para impress�o
	syscall			#imprime
	addi $s1, $s1, -1	#reduz contador em uma unidade
	j imprime		#retorna para nova impress�o
sai:
	li $v0, 10		#carrega comando de encerramento
	syscall			#encerra
	