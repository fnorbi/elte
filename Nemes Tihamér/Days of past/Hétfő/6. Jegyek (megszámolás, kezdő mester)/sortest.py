l = [0, 0, 0, 0, 0]; n = int(input())
for i in range(n): l[int(input()) - 1] += 1
for i in l: print(str(i), end = " ")
