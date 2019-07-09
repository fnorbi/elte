n = int(input())
lista = []
for i in range(n):
    lista.append(int(input()))

mini = 0; mine = lista[0]
for i in range(1,n):
    if(lista[i] < mine):
        mini = i
        mine = lista[i]

print(mine)