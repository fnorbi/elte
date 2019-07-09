#Olvassunk be 3 számot és adjuk meg melyik a legnagyobb
lista = input().split()
print(lista)
#Első megoldás:
lista2 = []
for i in lista:
    lista2.append(int(i))
print(lista2)
#Második megoldás: map
lista = map(int, lista)
print(lista)
#Nem lista, konverzió kell: list
lista = list(lista)
print(lista)
#print(list(map(int,input().split())))
#lista = list(map(int,input().split()))

#Maximum?
if lista[0] > lista[1] and lista[0] > lista[2]:
    print(lista[0])
elif lista[1] > lista[2]:
    print(lista[1])
else:
    print(lista[2])
#Sok elem esetén mit lehetne csinálni?
maxert = lista[0]
if(lista[1] > maxert):
    maxert = lista[1]
if(lista[2] > maxert):
    maxert = lista[2]
print(maxert)