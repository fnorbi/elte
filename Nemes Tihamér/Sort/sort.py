class Rec(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return self.name + " " + self.age
    def __lt__(self, other):
        return self.age < other.age

def kiir(adatok):
    for r in adatok:
        print (r)

def main():
    #n = input() Python 2
    n = int(input())
    adatok = []
    for i in range(0,n):
        #s = raw_input() Python 2
        s = input()
        temp = s.split()
        rec = Rec(temp[0],temp[1])
        adatok.append(rec)

    kiir(adatok)
    print()

    adatok.sort()
    #adatok = sorted(adatok, reverse = True)

    kiir(adatok)
    
main()