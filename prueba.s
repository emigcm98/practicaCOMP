############################
	.data

# STRINGS ##################
$Str1:
	.asciiz  "\n"
$Str2:
	.asciiz  "i:= "
$Str3:
	.asciiz  "\n"

# IDENTIFIERS ##############
_i:
	.word 0

	.text
	.globl main

main:
	li $t0, 20
	sw $t0, _i
	li $t0, 1
	sw $t0, _i
	lw $t2, _i
	li $t1, 5
$l1:
	bgt $t2, $t1, $l2
	lw $t2, _i
	move $a0, $t2
	li $v0, 1
	syscall 
	la $a0, $Str1
	li $v0, 4
	syscall 
	addiu $t2, $t2, 1
	sw $t2, _i
	b $l1
$l2:
	la $a0, $Str2
	li $v0, 4
	syscall 
	lw $t3, _i
	move $a0, $t3
	li $v0, 1
	syscall 
	la $a0, $Str3
	li $v0, 4
	syscall 
	li $v0, 10
	syscall 

#----------------------
#errores léxicos: 0
#errores sintacticos: 0
#errores semánticos: 0
