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
	la $t0, vetor		#guarda o endereço do início do vetor
	la $t1, size_vet	#guarda o endereço com o tamanho do vetor
	la $a0, msg_1		#guarda o endereço da mensagem 1
	li $v0, 4		#imprime mensagem 1
	syscall
	li $v0, 5		#recebe o tamanho do vetor
	syscall
	sw $v0, 0($t1)		#guarda na memoria o valor do tamanho do vetor
	lw $t1, 0($t1)		#guarda o tamanho do vetor no registrador
	addi $t6, $t1, 0	#copia o tamanho do vetor (usado para receber valores)
	
for0: 	beqz $t6, atrib		#confere se o vetor já recebeu todos os dados
	li $v0, 5		#recebe um inteiro do usuário
	syscall
	sw $v0, 0($t0)		#guarda o valor recebido na memória
	addi $t0, $t0, 4	#vai para a próxima posição de memória
	addi $t6, $t6, -1	#reduz uma unidade no contador do vetor
	j for0			#salta para receber o próximo valor
	
atrib:	add $s0, $t1, $zero	#copia o tamanho do vetor para outro registrador
	la $t0, vetor		#guarda o endereço do início do vetor
	add $t5, $t0, $zero	#guarda no registrador o inicio do vetor
	
for1: 	
	beqz $s0, sai		#Compara se o contador global é igual a zero
	addi $t6, $s0, -1	#atribui o valor final da ordenação
	add $t0, $t5, $zero	#reseta o inicio do vetor
	addi $s0, $s0, -1	#reduz o contador global de uma unidade
buble: 	
	beqz $t6, for1		#Realiza a comparação para ordenação (BOLHA)
	lw $t3, 4($t0)		#carrega o valor do segundo indice do vetor
	lw $t2, 0($t0)		#carrega o valor do primeiro indice do vetor
	bgt $t3, $t2, loop	#Compara se o segundo valor do vetor é menor que o primeiro
	lw $t4, 0($t0)		#carrega o segundo valor em variável auxiliar
	sw $t3, 0($t0)		#guarda o primeiro valor no lugar do segundo
	sw $t4, 4($t0)		#guarda o valor que está em auxiliar no primeiro lugar do vetor
loop:	
	addi $t0, $t0, 4	#vai para o próximo endereço de memória
	addi $t6, $t6, -1	#diminui um no contador local
	j buble			#retorna para a comparação e ordenação (BOLHA)

sai:
	add $t0, $t5, $zero	#Reseta o início do vetor
	add $t6, $t1, $zero	#Carrega o tamanho do vetor
	la $a0, msg_2		#carrega endereço de impressão
	li $v0, 4
	syscall
loop2:	
	beqz $t6, decre		#Compara se o vetor terminou
	lw $a0, 0($t0)		#carrega dado para impressão
	li $v0, 1		#carrega comando de impressão
	syscall			#imprime
	la $a0, space		#carrega dado para impressão
	li $v0, 4		#carrega comando de impressão
	syscall			#imprime
	add $t0, $t0, 4		#próxima posição do vetor
	addi $t6, $t6, -1	#subtrai um do contador local
	j loop2			#retorna para a comparação

decre:	addi $t0, $t0, -4	#volta ao último valor do vetor
	add $t6, $t1, $zero	#reseta tamanho do vetor
	la $a0, msg_3		#carrega endereço de mensagem para impressão
	li $v0, 4
	syscall
	
loop3:	beqz $t6, fim		#Compara se o vetor terminou
	lw $a0, 0($t0)		#carrega dado para impressão
	li $v0, 1		#carrega comando de impressão
	syscall			#imprime
	la $a0, space		#carrega dado para impressão
	li $v0, 4		#carrega comando de impressão
	syscall			#imprime
	addi $t0, $t0, -4	#posição anterior do vetor
	addi $t6, $t6, -1	#subtrai um do contador local
	j loop3			#retorna para a comparação
fim:
	li $v0, 10		#carrega comando de encerramento
	syscall			#Encerra programa
