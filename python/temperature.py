v = []

while(True):
    temp = input()
    if temp == 'off':
        break
    else:
        temp = float(temp)
        v.append(temp)

if(len(v)>0):
    print("{:.1f}".format(v[0]))

if(len(v)>1):
    print("{:.1f}".format((v[0]+v[1])/2.0))

    for i in range(len(v)-2):
        soma = v[i] + v[i+1] + v[i+2]
        print("{:.1f}".format(soma/3.0))