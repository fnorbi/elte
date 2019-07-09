from sys import stdin, stdout

#a = input()
#b = input()
a = str(stdin.readline())
b = str(stdin.readline())

i = 0
while(i < len(a)-1 and a[i] == b[i]): #mert a len(a)-1 a sorvégjel
    stdout.write(str(a[i]))
    #print(a[i], end = "")
    i += 1
print()

db = 0
for i in a:
    if i == b[db]:
        stdout.write(str(i))
        #print(i, end = "")
        db += 1