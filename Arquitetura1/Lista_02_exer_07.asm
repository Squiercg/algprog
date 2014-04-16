#Exercicio 06			DOGLAS WENDLL SORGATTO
a) AE0BFFFC
sw $t3, 65532($s0)	#tipo I

b) 8D08FFC0
lw $t0, 65472 ($t0)	#tipo I

c) 01090010		#Tipo R
mfhi $t1 		#quociente da divisão de $t0 por $t1

d) 8D090012		#Tipo I
lw $t1, 18($t0)

e) 02538820		#tipo R
add $s1, $s2, $s3

f) 02538822		#Tipo R
sub $s1, $s2, $s3

g) 8E510100		#Tipo I
lw $s1, 256($s2)

h) 0C000E1A		#tipo J
jal 3610		#Endereço do label