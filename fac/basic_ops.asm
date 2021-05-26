.data
	endl: .asciiz "\n"
	add: .asciiz "ADD: "
	sub: .asciiz "SUB: "
	and: .asciiz "AND: "
	or: .asciiz "OR: "
	xor: .asciiz "XOR: "
	sll: .asciiz "SLL(3): "
	srl: .asciiz "SRL(1): "

.text
main:
	# leitura dos dois inteiros
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 5
	syscall
	move $t1, $v0
	
	# soma
	add $t2, $t0, $t1
	
	li $v0, 4
	la $a0, add
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	# subtração
	sub $t2, $t0, $t1
	
	li $v0, 4
	la $a0, sub
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	# and
	and $t2, $t0, $t1
	
	li $v0, 4
	la $a0, and
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	# or
	or $t2, $t0, $t1
	
	li $v0, 4
	la $a0, or
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	# xor
	xor $t2, $t0, $t1
	
	li $v0, 4
	la $a0, xor
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	# sll
	sll  $t2, $t0, 3
	
	li $v0, 4
	la $a0, sll
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	# srl
	srl $t2, $t1, 1
	
	li $v0, 4
	la $a0, srl
	syscall
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	# sair
	li $v0, 10
	syscall