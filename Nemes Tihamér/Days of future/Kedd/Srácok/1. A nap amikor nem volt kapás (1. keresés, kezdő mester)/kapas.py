n = int(input())
lista = []
for i in range(n):
    lista.append(int(input()))

i = 0
while(i < n and lista[i] != 0):
    i += 1

if(i < n):
    print(i+1)
else:
    print(-1)