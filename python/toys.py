n = int(input())
list = input().split()
toys = []

for i in range(n):
  toy = [list[i],i]
  toys.append(toy)

for i in range(5):
  move = input().split()
  j=0
  while toys[j][0] != move[0]:
    j+=1
  for k in range(int(move[2])):
    if move[1] == 'D' and j<n-1:
      aux = toys[j]
      toys[j] = toys[j+1]
      toys[j+1] = aux
      j+=1
    elif move[1] == 'E' and j>0:
      aux = toys[j]
      toys[j] = toys[j-1]
      toys[j-1] = aux
      j-=1
qtd=0
for i in range(n):
  if i != toys[i][1]:
    qtd += 1 
print(qtd)
