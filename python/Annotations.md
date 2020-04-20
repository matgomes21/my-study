# My python studies

## By: Mateus Gomes, from Brazil

In this repository I'll put my annotations and practise in Python. (I hope future me will be thankfull)

## To use portuguese special characters

```# -*- coding: utf-8 -*-```

## Identation == Important (this comparation returns true)

## Data type

In python, you don't need to specify what data type you are using in the variable declaration, it automatically determinates the type based on the value assigned to the variable.

> Examples of variable declaration

* int: x = 1
* float: y = 3.7
* string: z = "Hello World!"
* boolean: b = True

## Print/Scan

* print("Hello World!) or print(z)
* number = input("Type a number: ")
* Concat: print("Your number is" + number)

## Conditioners

* if
* else
* elif

## Repetition Structures

* for
* while

> Example for *while*:

``` python
i=0
while i < 3:
    print(i)
    i+=1
```

This code might print:

``` python
0
1
2
```

> Example for *for*:

``` python
for i in range(10,20,2) #'i' will start on 10, will go to 20-1, in passes from 2 to 2
    print(i)
```

This code might print:

``` python
10
12
14
16
18
```

## Lists

* list1 = [1,2,3,4,5]
* list2 = ["Hello","World","!"]
* list3 = [0,"Dale",7.98,True]

> Example:

``` python
list = ["Hello", 3, "World",7.77]
for i in list:
    print(i)
```

This code might print:  

``` python
Hello
3
World
7.77
```

* Adding new elements:

``` python
list.append("dale")

print(list)
```

Print result:

``` python
['Hello', 3, 'World', 7.77, 'dale']
```

* Knowing if an element exists in a list:

``` python
if 3 in list:
    print("3 is in the list")
```

* Deleting elements in lists:

``` python
del lista[2:]
print(lista)
```

Print result:

``` python
['Hello', 3]
```

To delete the whole list:

``` python
del lista[:]
```

* Sorting elements of a list:

``` python
list = [124,345,5,72]

list.sort()
```

The list is now sorted.

> Obs: the function sorted returns a sorted list but not subscribes the original list.

*Sorting backwards:

``` python
list.sort(reverse=True)
```

* Inverting a list:

``` python
list.reverse()
```

## Strings

* Concat strings:

``` python
a = "Mateus"
b = "Gomes"

concat = a + " " + b
print(concat)
```

Print result:

``` python
Mateus Gomes
```

* String lenght

Function len()

``` python
print(len(concat))
```

Print result:

``` python
12
```

* String index

``` python
print(a[2])
print(a[3])
```

Print result:

``` python
at
```

``` python
print(a[0:4])
```

Print result:

``` python
Mate
```

``` python
print(concat[2:])
```

Print result:

``` python
teus Gomes
```

* Function Lower and Upper

``` python
a = "Dale"
print(a.lower())
print(a.upper())
print(a)
```

This code might print:

``` python
dale
DALE
Dale
```

* Function Strip

Will remove innoportune characters localizated at the end of a string

``` python
a = "Mateus"
b = "Gomes"
c = a + " " + b + "\n"

print(c.strip())
```

This code will print c without the "\n"

* Function Split  

Transforms a string into a list. #case sensitive (Diferencia maiúsculas)

``` python
string = "O rato roeu a roupa do rei de Roma"

list = string.split(" ")
print(list)
```

Print result:

``` python
['O', 'rato', 'roeu', 'a', 'roupa', 'do', 'rei', 'de', 'Roma']
```

* Function Find  

``` python
string = "O rato roeu a roupa do rei de Roma"

loc = string.find("rei")

print(loc)
```

Print result:  

``` python
23
```

Obs: Returns -1 if the word is not finded.  

* Function replace

``` python
string = "O rato roeu a roupa do rei de Roma"

string = string.replace("o rei", "a rainha")

print(string)
```

Print result:

``` python
O rato roeu a roupa da rainha de Roma
```

## Functions

``` python
def summ(x,y):
   return x+y

print(summ(2,3))
```

Obs: escopo local

## Archives

...

## Dictionaries

``` python
my_dict = {"A":"AMEIXA", "B":"BOLA", "C":"CACHORRO"}

print(my_dict["B"])
```

Print result:

``` python
BOLA
```

``` python
for key in my_dict:
    print(my_dict[chave])
```

Print result:

``` python
AMEIXA
BOLA
CACHORRO
```

``` python
for i in my_dict.items()
    print (i)

for i in my_dict.values()
    print (i)

for i in my_dict.keys()
    print (i)
```

## Random numbers

``` python
import random

number = random.randint(0, 10)
print(number)
```

Randomizes a number between 0 and 10

* Forcing the same number

``` python
random.seed()
```

* Using list

``` python
import random

list = [6,45,9]
number = random.choice(list)
```

Number will be a random element of the list.

## Exceptions

> Example of an error code:

``` python
a = 2
b = 0

print(a/b)
```

> How to treat this exception:

``` python
a = 2
b = 0

try:
    print(a/b)

except:
    print("It's not allowed 0 division")
```

Exception treatments permits the code go on with an error, displaying to the user what mistake happened but not stoping the execution of the code.

## List Comprehension

```python
values = [expression for value in collection if condition]
```

> Example:

```python
even_squares = [x * x for x in range(10) if x % 2 == 0]
```

