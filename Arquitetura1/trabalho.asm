#Augusto Ribas, Doglas Sorgatto, Thiago Imperial 
.data				
		
	matrizA: .asciiz "Entre com os valores da matriz A\n"
	matrizB: .asciiz "Entre com os valores da matriz B\n"
	resultado: .asciiz "\nResultado\n" 
	menu_1: .asciiz "\n1: Somar Matriz\n"
        menu_2: .asciiz "2: Subtrair Matriz\n"
        menu_3: .asciiz "3: Multiplicar Matriz\n"
        menu_4: .asciiz "4: Determinante da Matriz\n"
        menu_5: .asciiz "5: Sair\n\n"
        
        A: .word 0 0 0 0 0 0 0 0 0
	B: .word 0 0 0 0 0 0 0 0 0
	C: .word 0 0 0 0 0 0 0 0 0
	
.text
.globl main

#Inicio do programa, aqui vamos abrir os dados, quantidades são fixas, então a principio não precisa
main:	
	la $s0, A	        #Matriz A
	la $s1, B	        #Matriz B
        la $s2, C	        #Matriz C, local para dados de saida 
        addi $t0, $zero, 9	#Quantidade de elementos    
	la $a0, matrizA         #String pedindo números da matriz A
        li $v0, 4               #Imprime o pedido		
	syscall
	add $t1, $s0, $zero
	jal recebe              #Vai receber os números
		
        addi $t0, $zero, 9	#reinicia a quantidade de elementos
	la $a0, matrizB         #mensagem de matriz B
        li $v0, 4		
	syscall
	add $t1, $s1, $zero
	jal recebe              #vai receber os números
	
	j menu

volta: jr $ra

#Procedimento para carregar os números na matriz
recebe:	beqz  $t0, volta	#Verifica se ja recebeu tudo
	li $v0, 5		#comando para leitura de inteiro
	syscall
	sw $v0, 0($t1)		#guarda o número recebido na matriz
	addi $t0, $t0, -1	#reduz uma unidade no contador de entradas
	addi $t1, $t1, 4
	j recebe		#volta para receber outro elemento ou encerrar

#Procedimento para imprimir o menu da memoria
menu:   la $a0, menu_1
        li $v0, 4		
	syscall
	la $a0, menu_2
        li $v0, 4		
	syscall
	la $a0, menu_3
        li $v0, 4		
	syscall
	la $a0, menu_4
        li $v0, 4		
	syscall
	la $a0, menu_5
        li $v0, 4		
	syscall
	
	li $v0, 5		#comando para leitura de inteiro, referente ao menu
	syscall
	
	beq $v0, 1 , soma #Se recebeu 1, vai para soma
	beq $v0, 2 , subtracao #Se recebeu 2, vai para subtracao
	beq $v0, 3 , multiplicacao #Se recebeu 3, vai para multiplicacao
	beq $v0, 4 , determinante #Se recebeu 4, vai para determinante
	
	j fim

########################
#Procedimento de soma #
#######################	
soma:
        addi $t0, $zero, 9
        add $t1, $s0, $zero
        add $t2, $s1, $zero
        add $t3, $s2, $zero
        j somarep
                    
somarep:
        beqz  $t0, imprime	#verifica se todos os elementos foram recebidos
        lw $t4, 0($t1) 
        lw $t5, 0($t2)
        add $t6, $t4, $t5
        sw $t6, 0($t3)
	addi $t0, $t0, -1	#reduz uma unidade no contador de entradas
	addi $t1, $t1, 4
	addi $t2, $t2, 4
	addi $t3, $t3, 4
	j somarep
	
############################
#Procedimento de subtracao #
############################	
subtracao:
        addi $t0, $zero, 9
        add $t1, $s0, $zero
        add $t2, $s1, $zero
        add $t3, $s2, $zero
        j subtracaorep
                      
subtracaorep:
        beqz  $t0, imprime	#verifica se todos os elementos foram recebidos
        lw $t4, 0($t1) 
        lw $t5, 0($t2)
        sub $t6, $t4, $t5
        sw $t6, 0($t3)
	addi $t0, $t0, -1	#reduz uma unidade no contador de entradas
	addi $t1, $t1, 4
	addi $t2, $t2, 4
	addi $t3, $t3, 4
	j subtracaorep
	
	
################################
#Procedimento de Multiplicacao #
###############################
#linha 1
#1,1  1*1+2*4+3*7
#1,2  1*2+2*5+3*8
#1,3  1*3+2*6+3*9
#linha 2
#2,1  4*1+5*4+6*7
#2,2  4*2+5*5+6*8
#2,3  4*3+5*6+6*9
#linha 3
#3,1  7*1+8*4+9*7  
#3,2  7*2+8*5+9*8
#3,3  7*3+8*6+9*9

multiplicacao:
        addi $t0, $zero, 9
        addi $t7 , $zero , 3
        add $t1, $s0, $zero
        add $t2, $s1, $zero
        add $t3, $s2, $zero
        j elemento

proximalinha:
	addi $t1, $t1, 4
	add $t2, $s1, $zero
	addi $t9 , $zero , 3
	j elemento 
               
elemento:
	beqz $t0, imprime
	beqz $t7, proximalinha
	add $t6, $zero, $zero
	
        lw $t4, 0($t1) 
        lw $t5, 0($t2)
        mul $t4, $t4 , $t5
        add $t6, $t6, $t4
        lw $t4, 4($t1) 
        lw $t5, 16($t2)
        mul $t4, $t4 , $t5
        add $t6, $t6, $t4
        lw $t4, 8($t1) 
        lw $t5, 28($t2)
        mul $t4, $t4 , $t5
        add $t6, $t6, $t4
        
        sw $t6, 0($t3)
        addi $t2, $t2, 4
        addi $t3, $t3, 4        
        addi $t0, $t0, -1
        addi $t9 , $9 , -1
        
        j elemento
        
        
################################
#Procedimento do Determinante #
###############################

#(1*5*9+2*6*7+3*4*8)-(3*5*7+1*6*8+4*2*9)
#(0 16 32 +  4 20 24 + 8 12 28) - (8 16 24 + 0 20 28 + 12  4 32)

determinante:
	add $t0, $s0, $zero
	lw $t1, 0($t0) 
        lw $t2, 16($t0)
        lw $t3, 32($t0)
        mul $t4, $t1, $t2
        mul $t4, $t4, $t3
        lw $t1, 4($t0) 
        lw $t2, 20($t0)
        lw $t3, 24($t0)
        mul $t5, $t1, $t2
        mul $t5, $t5, $t3
        lw $t1, 8($t0) 
        lw $t2, 12($t0)
        lw $t3, 28($t0)
        mul $t6, $t1, $t2
        mul $t6, $t6, $t3
        add $t7, $t4, $t5
        add $t7, $t7, $t6 
        
        lw $t1, 8($t0) 
        lw $t2, 16($t0)
        lw $t3, 24($t0)
        mul $t4, $t1, $t2
        mul $t4, $t4, $t3
        lw $t1, 0($t0) 
        lw $t2, 20($t0)
        lw $t3, 28($t0)
        mul $t5, $t1, $t2
        mul $t5, $t5, $t3
        lw $t1, 12($t0) 
        lw $t2, 4($t0)
        lw $t3, 32($t0)
        mul $t6, $t1, $t2
        mul $t6, $t6, $t3
        add $t8, $t4, $t5
        add $t8, $t8, $t6 
        
        sub $t0, $t7, $t8 
        
        la $a0, resultado	#carrega string para impressao
	li $v0, 4		#comando da impressao de string
	syscall
	add $a0, $t0, $zero	#carrega determinante para impressao
	li $v0, 1		#carrega comando de de inteiro
	syscall			  
        li $a0, '\n'		#carrega caracter para impressao
	li $v0, 11		#carrega comando de impressao de caracter
	syscall
	
	j menu
		         

############################
#Procedimento de Impressão #
############################
imprime:
	addi $t0, $zero, 9
	addi $t1, $zero, 3	
	add $t2, $s2, $zero
	la $a0, resultado		#carrega dado para impressao
	li $v0, 4		#carrega comando de impressao
	syscall	
	j imprimerep

imprimevolta:
        li $a0, '\n'		#carrega dado para impressao
	li $v0, 11		#carrega comando de impressao
	syscall	
	j menu

pulalinha:
        li $a0, '\n'		#carrega dado para impressao
	li $v0, 11		#carrega comando de impressao
	syscall			#imprime
	addi $t1, $zero, 3
	j imprimerep
	
imprimerep:
	beqz  $t0, imprimevolta
	lw $t3, 0($t2)
	add $a0, $t3, $zero	#carrega dado para impressao
	li $v0, 1		#carrega comando de impressao
	syscall			#imprime
        li $a0, ' '		#carrega dado para impressao
	li $v0, 11		#carrega comando de impressao
	syscall			#imprime
	addi $t0, $t0, -1
	addi $t1, $t1, -1
	beqz  $t1, pulalinha	
	j imprimerep

############################
#fim do programa           #
############################
fim:
	li $v0, 10		#carrega comando de encerramento
	syscall			#Encerra programa
