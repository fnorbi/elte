#!/usr/bin/env python

class Fa:
    def __init__(self, tav, mag):
        self.tav = tav
        self.mag = mag

n = int(input())
adatok = []

for i in range(n):
    temp = input().split()
    fa = Fa(int(temp[0]), int(temp[1]))
    adatok.append(fa)

db = 1 #kidöntendő fák száma, elsőt mindenképp ki kell
lastmaxindex = 0 #legtovább elérő kidöntött fa indexe
maxi = 0; maxe = 0 #a legtöbbet kidöntő fa indexe és maximum értéke
loki = 0; lokdb = 0 #a jelenleg vizsgált fa hányat dönt ki: addig növeljük míg dönti ki a fákat

for i in range(1,n):
    tav = adatok[i].tav - adatok[lastmaxindex].tav
    #ha nem dől ki
    if(adatok[lastmaxindex].mag <= tav):
        db += 1
        if(lokdb > maxe):
            maxe = lokdb
            maxi = loki
        loki = i
        lokdb = 0
    else:
        lokdb += 1
    #ha a mostani tovább elér
    if(adatok[i].mag > adatok[lastmaxindex].mag - tav):
        lastmaxindex = i

#utolsó fa is döntheti ki a legtöbbet
if(lokdb > maxe):
    maxe = lokdb
    maxi = loki

print(db)
print(maxi + 1)
