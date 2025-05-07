##################
# Seccion de datos
	.data

$str1: 
	.asciiz "\n" 
_i: 
	.word 0 
_j: 
	.word 0 
_resultado: 
	.word 0 
###################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0, 0
	sw $t0, _resultado
	li $t0, 1
	sw $t0, _i
$l1: 
	lw $t0, _i
	li $t1, 5
	bgt $t0, $t1, $l2
	lw $t2, _resultado
	lw $t3, _i
	add $t4, $t2, $t3
	sw $t4, _resultado
	addi $t0, $t0, 1
	sw $t0, _i
	j $l1
$l2: 
	lw $t0, _resultado
	move $a0, $t0
	li $v0, 1
	syscall
	la $a0, $str1
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, _resultado
	li $t0, 3
	sw $t0, _i
$l3: 
	lw $t0, _i
	li $t1, 7
	bgt $t0, $t1, $l4
	lw $t2, _resultado
	lw $t3, _i
	add $t4, $t2, $t3
	sw $t4, _resultado
	addi $t0, $t0, 1
	sw $t0, _i
	j $l3
$l4: 
	lw $t0, _resultado
	move $a0, $t0
	li $v0, 1
	syscall
	li $t0, 1
	sw $t0, _j
$l5: 
	lw $t0, _j
	li $t1, 4
	bgt $t0, $t1, $l6
	lw $t2, _j
	li $t3, 2
	mul $t4, $t2, $t3
	sw $t4, _resultado
	lw $t2, _resultado
	move $a0, $t2
	li $v0, 1
	syscall
	addi $t0, $t0, 1
	sw $t0, _j
	j $l5
$l6: 
	li $t0, 0
	sw $t0, _resultado
	li $t0, 1
	sw $t0, _i
$l7: 
	lw $t0, _i
	li $t1, 3
	bgt $t0, $t1, $l8
	lw $t2, _resultado
	lw $t3, _i
	lw $t4, _i
	mul $t5, $t3, $t4
	add $t3, $t2, $t5
	sw $t3, _resultado
	addi $t0, $t0, 1
	sw $t0, _i
	j $l7
$l8: 
	lw $t0, _resultado
	move $a0, $t0
	li $v0, 1
	syscall

##############
# Fin
	li $v0, 10
	syscall
