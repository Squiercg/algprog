.data				#DOGLAS WENDLL SORGATTO
	vetor: .word
	size_vet: .word
	space: .asciiz " "
	msg_1: .asciiz "Entre com tamanho do vetor: "
	msg_2: .asciiz "\nVetor Crescente:\n"
	msg_3: .asciiz "\nVetor decrescente:\n"
.text
.globl main
main:	
	la $t0, vetor		#guarda o endere�o do in�cio do vetor
	la $t1, size_vet	#guarda o endere�o com o tamanho do vetor
	la $a0, msg_1		#guarda o endere�o da mensagem 1
	li $v0, 4		#imprime mensagem 1
	syscall
	li $v0, 5		#recebe o tamanho do vetor
	syscall
	sw $v0, 0($t1)		#guarda na memoria o valor do tamanho do vetor
	lw $t1, 0($t1)		#guarda o tamanho do vetor no registrador
	addi $t6, $t1, 0	#copia o tamanho do vetor (usado para receber valores)
	
for0: 	beqz $t6, atrib		#confere se o vetor j� recebeu todos os dados
	li $v0, 5		#recebe um inteiro do usu�rio
	syscall
	sw $v0, 0($t0)		#guarda o valor recebido na mem�ria
	addi $t0, $t0, 4	#vai para a pr�xima posi��o de mem�ria
	addi $t6, $t6, -1	#reduz uma unidade no contador do vetor
	j for0			#salta para receber o pr�ximo valor
	
atrib:	add $s0, $t1, $zero	#copia o tamanho do vetor para outro registrador
	la $t0, vetor		#guarda o endere�o do in�cio do vetor
	add $t5, $t0, $zero	#guarda no registrador o inicio do vetor
	
for1: 	
	beqz $s0, sai		#Compara se o contador global � igual a zero
	addi $t6, $s0, -1	#atribui o valor final da ordena��o
	add $t0, $t5, $zero	#reseta o inicio do vetor
	addi $s0, $s0, -1	#reduz o contador global de uma unidade
buble: 	
	beqz $t6, for1		#Realiza a compara��o para ordena��o (BOLHA)
	lw $t3, 4($t0)		#carrega o valor do segundo indice do vetor
	lw $t2, 0($t0)		#carrega o valor do primeiro indice do vetor
	bgt $t3, $t2, loop	#Compara se o segundo valor do vetor � menor que o primeiro
	lw $t4, 0($t0)		#carrega o segundo valor em vari�vel auxiliar
	sw $t3, 0($t0)		#guarda o primeiro valor no lugar do segundo
	sw $t4, 4($t0)		#guarda o valor que est� em auxiliar no primeiro lugar do vetor
loop:	
	addi $t0, $t0, 4	#vai para o pr�ximo endere�o de mem�ria
	addi $t6, $t6, -1	#diminui um no contador local
	j buble			#retorna para a compara��o e ordena��o (BOLHA)

sai:
	add $t0, $t5, $zero	#Reseta o in�cio do vetor
	add $t6, $t1, $zero	#Carrega o tamanho do vetor
	la $a0, msg_2		#carrega endere�o de impress�o
	li $v0, 4
	syscall
loop2:	
	beqz $t6, decre		#Compara se o vetor terminou
	lw $a0, 0($t0)		#carrega dado para impress�o
	li $v0, 1		#carrega comando de impress�o
	syscall			#imprime
	la $a0, space		#carrega dado para impress�o
	li $v0, 4		#carrega comando de impress�o
	syscall			#imprime
	add $t0, $t0, 4		#pr�xima posi��o do vetor
	addi $t6, $t6, -1	#subtrai um do contador local
	j loop2			#retorna para a compara��o

decre:	addi $t0, $t0, -4	#volta ao �ltimo valor do vetor
	add $t6, $t1, $zero	#reseta tamanho do vetor
	la $a0, msg_3		#carrega endere�o de mensagem para impress�o
	li $v0, 4
	syscall
	
loop3:	beqz $t6, fim		#Compara se o vetor terminou
	lw $a0, 0($t0)		#carrega dado para impress�o
	li $v0, 1		#carrega comando de impress�o
	syscall			#imprime
	la $a0, space		#carrega dado para impress�o
	li $v0, 4		#carrega comando de impress�o
	syscall			#imprime
	addi $t0, $t0, -4	#posi��o anterior do vetor
	addi $t6, $t6, -1	#subtrai um do contador local
	j loop3			#retorna para a compara��o
fim:
	li $v0, 10		#carrega comando de encerramento
	syscall			#Encerra programa
