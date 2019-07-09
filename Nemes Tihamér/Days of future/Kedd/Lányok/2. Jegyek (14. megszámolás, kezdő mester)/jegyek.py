l = [0, 0, 0, 0, 0]
n = int(input())
for i in range(n):
    jegy = int(input())
    l[jegy-1] += 1
for i in l:
    print(i, end = " ")