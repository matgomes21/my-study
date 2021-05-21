def findTarget(target,friends,n):
  i=n-1
  look = friends[i]
  count = 1
  while look[1] != target:
    count+=1
    nextT = look[1]
    j = 0
    friends.pop(i)
    while j < len(friends) and friends[j][0] != nextT:
      j+=1
    if j < len(friends):
      look = friends[j]
      i = j
    else:
      i = j-1
      look = friends[i]
  return count

n = int(input())

friends = []

for i in range(n):
  friend = input().split()
  friend.append(i)
  friends.append(friend)

target = input()

print(findTarget(target, friends, n))