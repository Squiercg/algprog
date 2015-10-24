.text			#DOGLAS WENDLL SORGATTO
.globl main
main: 	li $s0, 123	#carrega 123 em $s0
	li $s1, 456	#carrega 456 em $s1
	li $s2, 789	#carrega 789 em $s2
	
	add $s3, $s0, $s1	#soma 123 com 456 e guarda em $s3
	add $s3, $s3, $s2	#soma o resultado que esta em $s3 com 789
	
	add $a0, $s3, $zero	#transfere o resultado para $a0
	li $v0, 1		#carrega o comando de impressão
	syscall			#imprime o resultado que está em $a0
	
	li $v0, 10		#carrega o comando de encerramento
	syscall			#encerra o sistema
	