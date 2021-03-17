"""
Em cada exercício, implemente uma gramática utilizando a sintaxe do Lark 
para identificar as linguagens consideradas.

Escolhemos alguns exemplos clássicos de linguagens simples que normalmente 
aparecem como partes de outras linguagens mais elaboradas. Tenha cuidado para 
que sua gramática identifique todos exemplos corretos e recuse todos os casos
incorretos.

Em cada exercício, complete a declaração da gramática na variável correspondente.
Não modifique o nome da variável nem os testes unitários.
"""


# Strings formadas por n a's seguidas de n b's; n >= 1. 
# Ex.: `aabb, ab, aaabbb`.
strings_pareadas = r""" 
start : "a" start? "b"
"""


# Letras L Dentro de parênteses pareados. 
# Ex.: `LL, (LL), L(L(LL)), (((L)(L)))`
letras_dentro_de_parenteses = r"""
start : expr+
expr: "(" expr+ ")" | letter+
letter : "L"
"""


# Listas com elementos separados por vírgulas. 
# Ex.: `[], [e], [e,e,e]`
listas_com_elementos_separados_por_virgulas = r"""
start : "[" expr? "]"
expr : letter repet*
repet : comma letter 
letter : "e"
comma: ","
"""


# Elementos e listas que podem conter outras listas. 
# Ex.: `e, [], [[]], [e], [e,[e,[]],e]`
listas_aninhadas = r"""
start : expr
expr: letter | letter (comma expr)* | bar (comma expr)* | bar
bar: "[" expr? "]"
letter : "e"
comma : ","
"""


# Expressões matemáticas no estilo prefixo. 
# Ex.: `42, + 1 2, + * 10 2 2`
operadores_prefixos = r"""
start : expr
expr  : NUMBER | OP SPACE expr SPACE expr
SPACE  : " "
OP     : "+" | "-" | "/" | "*" | "^"
NUMBER : "0" | ("0".."9") ("0".."9")*
"""