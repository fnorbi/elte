n, m = list(map(int,input().split()))
lista = [0] * n
for i in range(m):
    e, v = map(int,input().split())
    for j in range(e,v): #balról zárt, jobbról nyílt intervallum
        lista[j] += 1
    
#print(u.count(0))
db = 0
for i in lista:
    if i == 0:
        db += 1
print(db)