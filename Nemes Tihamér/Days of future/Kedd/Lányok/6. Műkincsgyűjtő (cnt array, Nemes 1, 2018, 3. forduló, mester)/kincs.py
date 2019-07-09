from sys import stdin, stdout

def main():
    #a = input()
    #b = input()
    n, p = list(map(int, stdin.readline().split()))

    k = [0] * 400000 #k[i]: az i+1 ár utolsó előfordulása

    i = 0; a = 0; b = 0
    while(i < n and b == 0):
        be = int(stdin.readline())
        kell = p - be
        if(kell > 0 and k[kell - 1] > 0):
            a = k[kell - 1]
            b = i + 1
        else:
            k[be - 1] = i + 1
        i += 1

    if b == 0:
        stdout.write(str(-1))
    else:
        stdout.write(str(a) + " " + str(b))

main()