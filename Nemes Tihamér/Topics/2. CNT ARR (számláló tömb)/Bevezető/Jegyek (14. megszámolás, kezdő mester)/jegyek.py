from sys import stdin, stdout
l = [0, 0, 0, 0, 0]; n = int(stdin.readline())
for i in range(n):
    l[int(stdin.readline())-1] += 1
for i in l: stdout.write(str(i) + " ")