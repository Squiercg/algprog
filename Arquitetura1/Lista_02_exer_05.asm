.data 				#DOGLAS WENDLL SORGATTO
	space: .asciiz " "
	
.text
.globl main
main: 	
	li $s0, 20		#quandidade de números a serem lidos
	addi $sp, $sp, -80	#reserva 20 posições na pilha
	add $s1, $s0, $zero	#copia o tamanho do vetor para outro registrador
recebe:
	beqz $s0, imprime	#compara se todos os números foram recebidos
	li $v0, 5		#comando para leitura de entrada
	syscall			#recebe entrada
	sw $v0, 0($sp)		#guarda entrada na pilha
	addi $sp, $sp, 4	#vai para o próximo endereço da pilha
	addi $s0, $s0, -1	#diminui o contador em uma unidade
	j recebe		#retorna para comparação e recebimento de números
imprime:
	addi $sp, $sp, -4	#diminui uma posição na pilha
	beqz $s1, sai		#compara se contador local está zerado
	lw $a0, 0($sp)		#carrega para impressão o valor do fim da pilha
	li $v0, 1		#carrega comado de impressão
	syscall			#imprime
	li $v0, 4		#carrega comando de impressão
	la $a0, space		#carrega informação para impressão
	syscall			#imprime
	addi $s1, $s1, -1	#reduz contador em uma unidade
	j imprime		#retorna para nova impressão
sai:
	li $v0, 10		#carrega comando de encerramento
	syscall			#encerra
	