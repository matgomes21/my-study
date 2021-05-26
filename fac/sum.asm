.data
	endl: .asciiz "\n"

.text
main:
	# ler primeiro inteiro
	li $v0, 5   # código de chamada ao sistema para read_int
	syscall   # lê o inteiro
	move $t0, $v0   # atribui o conteúdo de v0 para t0
	
	# ler segundo inteiro
	li $v0, 5   # código de chamada ao sistema para read_int
	syscall   # lê o inteiro	
	move $t1, $v0   # atribui o conteúdo de v0 para t1
	
	# somar inteiros
	add $t2, $t1, $t0   # atribui o resultado da soma de t1 com t0 para t2
	
	# imprimir soma
	li $v0, 1   # código de chamada ao sistema para print_int
	move $a0, $t2   # endereço do inteiro a imprimir
	syscall   # imprime
	
	# imprimir quebra de linha
	li $v0, 4   # código de chamada ao sistema para print_str
	la $a0, endl   # endereço da string a imprimir
	syscall   # imprime
	
	# sair
	li $v0, 10   # código de chamada ao sistema para exit
	syscall   # sai do programa