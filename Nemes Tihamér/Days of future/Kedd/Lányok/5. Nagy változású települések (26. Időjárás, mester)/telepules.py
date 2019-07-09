from sys import stdin, stdout

def main():

    # n, m = list(map(int, stdin.readline().split()))

    # l = [] #l = [[]] nem jó, mert az egy egye elemű tömb
    # for i in range(n):
    #     line = list(map(int, stdin.readline().split()))
    #     l.append(line)

    # db = 0; lista = []
    # for i in range(n):
    #     j = 0
    #     while(j < m - 1 and abs(l[i][j] - l[i][j+1]) < 10):
    #         j += 1
    #     if(j < m - 1):
    #         db += 1
    #         lista.append(i + 1)

    # stdout.write(str(db) + " ")
    # for i in range(db):
    #     stdout.write(str(lista[i]) + " ")

    n, m = list(map(int, stdin.readline().split()))

    db = 0; lista = []
    for i in range(n):
        line = list(map(int, stdin.readline().split()))
        # j = 0
        # while(j < m - 1 and abs(line[j] - line[j+1]) < 10):
        #     j += 1
        # if(j < m - 1):
        #     db += 1
        #     lista.append(i + 1)

    # stdout.write(str(db) + " ")
    # for i in range(db):
    #     stdout.write(str(lista[i]) + " ")

main()