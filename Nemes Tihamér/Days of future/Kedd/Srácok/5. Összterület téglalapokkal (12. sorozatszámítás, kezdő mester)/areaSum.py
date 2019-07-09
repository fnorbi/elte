# n = int(input())
# s = 0
# for i in range(n):
#     lista = list(map(int, input().split()))
#     s += lista[0] * lista[1]
# print(s)

class rec:
    def __init__(self, a, b):
        self.a = a
        self.b = b

n = int(input())
lista = []
for i in range(n):
    temp = list(map(int, input().split()))
    p = rec(temp[0], temp[1])
    lista.append(p)
s = 0
for i in lista:
    s += i.a * i.b
print(s)