#Olvassunk be egy n számot!
n = int(input())
#Írjuk ki n-ig a számokat! range(a,b)
for i in range(1,n+1):
    print(i)
#Most csak azokat amik oszthatóak 3-mal! a % b
print("For ciklussal: ")
for i in range(0,n):
    if (i % 3 == 0):
        print(i)
#Hogyan lehetne máshogy?
print("While ciklussal: ")
i = 0
while 3 * i < n:
    print(3 * i)
    i = i + 1
