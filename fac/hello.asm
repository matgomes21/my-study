.data
	msg: .asciiz "Ola, mundo!!\n"

.text
main:
	# imprimir string
	li $v0, 4   # c�digo de chamada ao sistema para print_str
	la $a0, msg   # endere�o da string a imprimir
	syscall   # imprime a string

	# sair
	li $v0, 10   # c�digo de chamada ao sistema para exit
	syscall   # sai do programa