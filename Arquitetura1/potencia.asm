#lembrando o esquema de potencia recursiva de forma eficiente
#X^n = 1                       Se n = 0
#X^n = x                       Se n =1
#X^n = (x^(n/2)) * (x^(n/2))   Se n > 1 e n é par
#X^n = x * (x^(n-1))           Se n > 1 e n é impar

#Então em C é esse esquema.
#potencia(int x, int n) {
#    if( n == 0 ) {
#        return 1;
#    } else {
#        if( n == 1 ) {
#            return x;
#        } else {
#            if( (n % 2) == 0 ) {
#                int temp = potencia(x,n/2);
#                return temp*temp;
#            } else {
#                return x*potencia(x, n )
#            }
#        }
#    }
#}



################
#Memoria de dados com strings
################
.data
str: .asciiz " Inteiro X:"
str1: .asciiz " Inteiro N:"
str2: .asciiz " X elevado a potencia N e : "
.text

################
#Main
################
main:
    la $a0,str
    li $v0,4
    syscall
    li $v0,5
    syscall
    move $t0,$v0
    la $a0,str1
    li $v0,4
    syscall
    li $v0,5
    syscall
    move $a1,$v0    #$a1=N    
    move $a0, $t0    #$a0=X
    jal Potencia
    move $s0,$v0 #copia o resultado pra usar o $v0 no syscal
    la $a0,str2 #imprime o texto
    li $v0,4
    syscall
    move $a0,$s0 #imprime o resultado 
    li $v0,1
    syscall
    li $v0,10 #termina o programa
    syscall

###########################
#Procedimentos
###########################
    Potencia: 
	addi $sp,$sp,-4 #abre um espaço na pilha
        sw $ra,0($sp)  #guarda o $ra na pilha, veja que o primeiro $ra é la da main, aqui que ta o esquema pra faze voltar na hora certa
        bne $a1,$zero, Else #se a potencia não chegou em zero
        addi $v0,$zero,1 #pega o resultado
        addi $sp, $sp,4 #limpa a pilha
        
        jr $ra #volta pra dar o resultado pra quem chamou
    Else:
	bne $a1,1, Par
        add $v0,$zero, $a0
        addi $sp,$sp,4
        
        jr $ra
        
    Par:    
	move $t1,$a1
        andi $t0, $t1,1        #Verifica se N é par ou impar
        bne $t0,$zero, Impar    #Impar vai para Impar
        srl $a1, $a1,1        #Par, então N/2
        jal Potencia        #Chamada da recursão, salva o $ra
        
        mul $v0,$v0,$v0        # Potencia(x,n/2)*Potencia(x,n/2), veja que na volta do potencia que a conta e feita
        lw $ra, 0($sp)
        addi $sp,$sp,4
        
        jr $ra
        
    Impar:    
	addi $a1,$a1,-1        #Impar X*potencia(x,n-1)
        jal Potencia           #mesma coisa, as contas são sempre na volta
        
        lw $ra, 0($sp)
        addi $sp,$sp,4
        mul $v0,$v0,$a0
        
        jr $ra