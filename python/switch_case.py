def calculator(op,x,y):
    return{
        '*': lambda: x*y,
        '+': lambda: x+y,
        '-': lambda: x-y,
        '/': lambda: x/y,
        '^': lambda: x**y,
    }.get(op, lambda: None)()

x = [float(input("Digite o primeiro numero: ")),
     float(input("Digite o segundo numero: ")),
     input("Digite o operador: ")]

print(calculator(x[2],x[0],x[1]))