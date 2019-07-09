#Mit csinál az alábbi kód?
l = ['c']
l.append(1)
print("A lista jelenlegi állapota: " + str(l))
n = int(input("Adj meg egy számot: "))
l.append(n)
print("A lista elemei: ")
for i in l:
    print(str(i) + " ", end = '') #Mi ez az end?
print() #Ennek mi a szerepe?
print("A lista jelenlegi állapota: " + str(l))
print(len(l)) #Mi ez a len(lista)?
