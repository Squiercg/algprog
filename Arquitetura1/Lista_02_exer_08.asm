.data 			#DOGLAS WENDLL SORGATTO
	qtde: .asciiz "N�mero de elementos no vetor: "
	insere: .asciiz "Insira os elementos: \n"
	maior_p: .asciiz "O maior elemento �: "
	posi: .asciiz "\nA posi��o do maior �: "
.text
.globl main
main:	la $a0, qtde		#carrega endere�o de string
	li $v0, 4		#comando para impress�o de string
	syscall
	li $v0, 5		#comando para leitura de inteiro
	syscall
	add $s0, $zero, $v0	#guarda a quantidade de elementos do vetor.
	add $t0, $s0, $zero	#copia a quantidade para um tempor�rio.
	sll $t1, $t0, 2		#multiplica a quantidade por 4 (usado para formar a pilha)
	sub $sp, $sp, $t1	#forma a pilha
	la $a0, insere		#carrega endere�o de string
	li $v0, 4		#comando para impress�o de string
	syscall
	
recebe:	beqz $t0, maior_1	#verifica se todos os elementos foram recebidos
	li $v0, 5		#comando para leitura de inteiro
	syscall
	sw $v0, 0($sp)		#guarda na pilha o valor da entrada
	addi $sp, $sp, 4	#avan�a uma posi��o de mem�ria
	addi $t0, $t0, -1	#reduz uma unidade no contador de entradas
	j recebe		#volta para receber outro elemento ou encerrar
	
maior_1:sub $sp, $sp, $t1	#volta para o in�cio da pilha
	add $t0, $s0, $zero	#copia a quatidade de elementos para um tempor�rio
maior:	beqz $t0, sai		#confere se acabou a pilha
	lw $s1, 0($sp)		#carrega o primeiro elemento da pilha
	lw $s2, 4($sp)		#carrega o segundo elemento da pilha
	bgt $s1, $s2, prox	#Verifica se o valor de s1 � maior que s2, se sim vai para proximo
cresce:	addi $sp, $sp, 4	#aumenta a pilha em uma unidade de mem�ria
	addi $t0, $t0, -1	#diminui uma posi��o no contador
	j maior			#volta para nova verifica��o
prox:	bgt $s3, $s1, pula	#verifica se o valor em s3 � maior que o de s1, se sim pula
	add $s3, $s1, $zero	#copia o valor maior para s3	
	sub $s4, $s0, $t0	#copia a posi��o do maior elemento
	addi $s4, $s4, 1	#aumenta um na posi��o (i+1)
pula:	addi $sp, $sp, 4	#aumenta a pilha em uma unidade de mem�ria
	addi $t0, $t0, -1	#diminui uma posi��o no contador
	j maior

sai:	la $a0, maior_p		#carrega endere�o de string
	li $v0, 4		#imprime string
	syscall
	add $a0, $s3, $zero	#carrega valor do maior n�mero
	li $v0, 1		#imprime inteiro
	syscall
	la $a0, posi		#carreg endere�o de string
	li $v0, 4		#imprime string
	syscall
	add $a0, $s4, $zero	#carrega valor da posi��o
	li $v0, 1		#imprime posi��o
	syscall
	li $v0, 10		#carrega encerramento do programa
	syscall
