.data			#DOGLAS WENDLL SORGATTO
	vetor_1: .word 1 3 5 7 9
	vetor_2: .word 0 2 4 6 8
	vetor_3: .word
	size: .word 5
	space: .asciiz " "
.text
.globl main
main:	
	la $t0, size		#carrega endereço do tamanho
	lw $t0, 0($t0)		#guarda o tamanho dos vetores
	la $t1, vetor_1		#carrega o endereço vetor 1
	la $t2, vetor_2		#carrega o endereço do vetor 2
	la $t3, vetor_3		#carrega endereço de vetor 3 (resultados)
	addi $t7, $t0, 0	#valor para acompanhar o tamanho de vetor 1
	addi $t6, $t0, 0	#valor para acompanhar o tamanho de vetor 2
	sll $t5, $t0, 1		#dobra o tamanho do vetor, para acompanhar o vetor 3 (resultado)
while:
	beqz $t5, imprime	#Verifica se o vetor de resultados está cheio
	bge $t6, $t7, outro	#compara se os índices atuais do vetor são maiores ou iguais
	lw $s0, 0($t1)		#carrega o proximo elemento do vetor
	sw $s0, 0($t3)		#Guarda no resultado o valor de s0
	addi $t1, $t1, 4	#aumenta uma posição no vetor	
	subi $t7, $t7, 1	#subtrai uma posição no índice do vetor
	j arruma		#salto incondicional
outro:	
	lw $s1, 0($t2)		#guarda o proximo elemento do vetor
	sw $s1, 0($t3)		#guarda no resultado o valor de s1
	addi $t2, $t2, 4	#proxima posição no vetor
	subi $t6, $t6, 1	#subtrai uma posição no índice do vetor
	j arruma		#salto incondicional
	
arruma:	addi $t3, $t3, 4	#proxima posição no vetor de resultados
	subi $t5, $t5, 1	#diminui uma posição no contador de resultados
	j while			#retorna para comparação

imprime:
	la $t1, vetor_3		#carrega endereço do vetor de resultados
	sll $t3, $t0, 1		#guarda em t3 o dobro do tamanho do vetor
loop:	beqz $t3, fim		#controla o indice do vetor de resultados
	lw $a0, 0($t1)		#carrega o valor a ser impresso
	li $v0, 1
	syscall
	la $a0, space		#imprime espaço
	li $v0, 4
	syscall
	addi $t1, $t1, 4	#vai para o proximo elemento do vetor de resultados
	subi $t3, $t3, 1	#diminui um no indice do vetor de resultados
	j loop			#salta para o controlador

fim:
	li $v0, 10
	syscall