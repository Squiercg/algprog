.data				#DOGLAS WENDLL SORGATTO
	vetor: .word 5 8 1 4 19 16 10 7 18 2 20 11 9 3 12 6 13 15 14 17
	size_vet: .word 20
	space: .asciiz " "
.text
.globl main
main:	
	la $t0, vetor		#guarda o endere�o do in�cio do vetor
	la $t1, size_vet	#guarda o endere�o com o tamanho do vetor
	lw $t1, 0($t1)		#guarda no registrador o valor do tamanho do vetor
	add $s0, $t1, $zero	#copia o tamanho do vetor para outro registrador
	add $t5, $t0, $zero	#guarda no registrador o inicio do vetor
	
for1: 	
	beqz $s0, sai		#Compara se o contador global � igual a zero
	addi $t1, $s0, -1	#atribui o valor final da ordena��o
	add $t0, $t5, $zero	#reseta o inicio do vetor
	addi $s0, $s0, -1	#reduz o contador global de uma unidade
buble: 	
	beqz $t1, for1		#Realiza a compara��o para ordena��o (BOLHA)
	lw $t3, 4($t0)		#carrega o valor do segundo indice do vetor
	lw $t2, 0($t0)		#carrega o valor do primeiro indice do vetor
	bgt $t3, $t2, loop	#Compara se o segundo valor do vetor � menor que o primeiro
	lw $t4, 0($t0)		#carrega o segundo valor em vari�vel auxiliar
	sw $t3, 0($t0)		#guarda o primeiro valor no lugar do segundo
	sw $t4, 4($t0)		#guarda o valor que est� em auxiliar no primeiro lugar do vetor
loop:	
	addi $t0, $t0, 4	#vai para o pr�ximo endere�o de mem�ria
	addi $t1, $t1, -1	#diminui um no contador local
	j buble			#retorna para a compara��o e ordena��o (BOLHA)

sai:
	add $t0, $t5, $zero	#Reseta o in�cio do vetor
	la $t6, size_vet	#Carrega o tamanho do vetor
	lw $t6, 0($t6)		#guarda o tamanho do vetor para ser usado
loop2:	
	beqz $t6, fim		#Compara se o vetor terminou
	lw $a0, 0($t0)		#carrega dado para impress�o
	li $v0, 1		#carrega comando de impress�o
	syscall			#imprime
	la $a0, space		#carrega dado para impress�o
	li $v0, 4		#carrega comando de impress�o
	syscall			#imprime
	add $t0, $t0, 4		#pr�xima posi��o do vetor
	addi $t6, $t6, -1	#subtrai um do contador local
	j loop2			#retorna para a compara��o
fim:
	li $v0, 10		#carrega comando de encerramento
	syscall			#Encerra programa