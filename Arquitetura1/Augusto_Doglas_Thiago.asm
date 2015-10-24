.data				#Doglas Sorgatto, Thiago Imperial, Augusto Ribas
	par: .asciiz "	par: "
	impar: .asciiz " impar "
.globl main 
.text 
 main:
	li $v0,5 # chamada de sistema que faz leitura de um inteiro scanf(%d,n);
	syscall # chama o sistema
	move $s0,$v0 #valor lido fica salvo em $v0 
	move $t0,$zero #valor i do for

for:
	bge $t0,$s0,fim #se for maior entao 
	div  $t1,$t0,2 #divide por 2
	mfhi $t1
	blez $t1,impa
	la $a0,impar
	li $v0,4
	syscall
	move $a0,$t0
	li $v0,1
	syscall 
	addi $t0,$t0,1
	j for

impa:
	la $a0,par
	li $v0,4
	syscall
	move $a0,$t0
	li $v0,1
	syscall 
	addi $t0,$t0,1
	j for
fim:
	li $v0,10 #fim do programa
	syscall #chamada do sistema
  