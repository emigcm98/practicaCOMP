##################
# Seccion de datos
	.data

$Str1:
	.asciiz  "b == "
$Str2:
	.asciiz  "\n"
$Str3:
	.asciiz  "b == "
$Str4:
	.asciiz  "\n"
_siguiente.c:
	.word 0
_b:
	.word 0

####################
 # Seccion de codigo
	.text
	.globl main

_siguiente:
	addiu $sp, $sp, -16
	sw $t2, 12 ($sp)
	sw $t1, 8 ($sp)
	sw $t0, 4 ($sp)
	sw $ra, 0 ($sp)
	move $v0, $zero
	beqz $a0, $l1
	li $t0, 1
	sub $t1, $a0, $t0
	move $a0, $t1
	jal _siguiente
	move $t0, $v0
	li $t1, 1
	add $t2, $t0, $t1
	move $v0, $t2
	b $l2
$l1:
	li $t0, 1
	move $v0, $t0
$l2:
	lw $ra, 0 ($sp)
	lw $t0, 4 ($sp)
	lw $t1, 8 ($sp)
	lw $t2, 12 ($sp)
	addiu $sp, $sp, 16
	jr $ra
main:
	li $t0, 5
	move $a0, $t0
	jal _siguiente
	move $t0, $v0
	sw $t0, _b
$l3:
	lw $t0, _b
	beqz $t0, $l4
	la $a0, $Str1
	li $v0, 4
	syscall 
	lw $t1, _b
	move $a0, $t1
	li $v0, 1
	syscall 
	la $a0, $Str2
	li $v0, 4
	syscall 
	lw $t1, _b
	li $t2, 1
	sub $t3, $t1, $t2
	sw $t3, _b
	b $l3
$l4:
	li $t1, 1
	sw $t1, _b
	lw $t1, _b
	li $t2, 10
$l5:
	bgt $t1, $t2, $l6
	la $a0, $Str3
	li $v0, 4
	syscall 
	lw $t3, _b
	move $a0, $t3
	li $v0, 1
	syscall 
	la $a0, $Str4
	li $v0, 4
	syscall 
	addiu $t1, $t1, 1
	sw $t1, _b
	b $l5
$l6:
	li $v0, 10
	syscall 

#----------------------
#errores léxicos: 0
#errores sintacticos: 0
#errores semánticos: 0
