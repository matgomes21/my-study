.data
	msg: .asciiz "Ola, mundo!!\n"

.text
main:
	# imprimir string
	li $v0, 4   # código de chamada ao sistema para print_str
	la $a0, msg   # endereço da string a imprimir
	syscall   # imprime a string

	# sair
	li $v0, 10   # código de chamada ao sistema para exit
	syscall   # sai do programa