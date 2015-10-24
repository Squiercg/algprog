.data 			#DOGLAS WENDLL SORGATTO
	qtde: .asciiz "Número de elementos no vetor: "
	insere: .asciiz "Insira os elementos: \n"
	maior_p: .asciiz "O maior elemento é: "
	posi: .asciiz "\nA posição do maior é: "
.text
.globl main
main:	la $a0, qtde		#carrega endereço de string
	li $v0, 4		#comando para impressão de string
	syscall
	li $v0, 5		#comando para leitura de inteiro
	syscall
	add $s0, $zero, $v0	#guarda a quantidade de elementos do vetor.
	add $t0, $s0, $zero	#copia a quantidade para um temporário.
	sll $t1, $t0, 2		#multiplica a quantidade por 4 (usado para formar a pilha)
	sub $sp, $sp, $t1	#forma a pilha
	la $a0, insere		#carrega endereço de string
	li $v0, 4		#comando para impressão de string
	syscall
	
recebe:	beqz $t0, maior_1	#verifica se todos os elementos foram recebidos
	li $v0, 5		#comando para leitura de inteiro
	syscall
	sw $v0, 0($sp)		#guarda na pilha o valor da entrada
	addi $sp, $sp, 4	#avança uma posição de memória
	addi $t0, $t0, -1	#reduz uma unidade no contador de entradas
	j recebe		#volta para receber outro elemento ou encerrar
	
maior_1:sub $sp, $sp, $t1	#volta para o início da pilha
	add $t0, $s0, $zero	#copia a quatidade de elementos para um temporário
maior:	beqz $t0, sai		#confere se acabou a pilha
	lw $s1, 0($sp)		#carrega o primeiro elemento da pilha
	lw $s2, 4($sp)		#carrega o segundo elemento da pilha
	bgt $s1, $s2, prox	#Verifica se o valor de s1 é maior que s2, se sim vai para proximo
cresce:	addi $sp, $sp, 4	#aumenta a pilha em uma unidade de memória
	addi $t0, $t0, -1	#diminui uma posição no contador
	j maior			#volta para nova verificação
prox:	bgt $s3, $s1, pula	#verifica se o valor em s3 é maior que o de s1, se sim pula
	add $s3, $s1, $zero	#copia o valor maior para s3	
	sub $s4, $s0, $t0	#copia a posição do maior elemento
	addi $s4, $s4, 1	#aumenta um na posição (i+1)
pula:	addi $sp, $sp, 4	#aumenta a pilha em uma unidade de memória
	addi $t0, $t0, -1	#diminui uma posição no contador
	j maior

sai:	la $a0, maior_p		#carrega endereço de string
	li $v0, 4		#imprime string
	syscall
	add $a0, $s3, $zero	#carrega valor do maior número
	li $v0, 1		#imprime inteiro
	syscall
	la $a0, posi		#carreg endereço de string
	li $v0, 4		#imprime string
	syscall
	add $a0, $s4, $zero	#carrega valor da posição
	li $v0, 1		#imprime posição
	syscall
	li $v0, 10		#carrega encerramento do programa
	syscall
