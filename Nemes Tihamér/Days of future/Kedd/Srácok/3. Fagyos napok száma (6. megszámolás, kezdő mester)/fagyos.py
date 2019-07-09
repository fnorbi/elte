n = int(input())
lista = []
for i in range(n):
    lista.append(int(input()))

db = 0
for i in range(n):
    if(lista[i] < 0):
        db += 1

print(db)