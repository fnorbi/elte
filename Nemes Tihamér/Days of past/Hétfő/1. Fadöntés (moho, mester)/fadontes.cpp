#include <iostream>

using namespace std;

const int MAXN = 1000;

struct fa
{
    int tav, mag;
};

int main()
{
    int n;
    cin >> n;
    fa adatok[MAXN];

    for(int i = 0; i < n; i++)
    {
        cin >> adatok[i].tav >> adatok[i].mag;
    }

    int db = 1; //kidöntendő fák száma, elsőt mindenképp ki kell
    int lastmaxindex = 0; //legtovább elérő kidöntött fa indexe
    int maxi = 0, maxe = 0; //a legtöbbet kidöntő fa indexe és maximum értéke
    int loki = 0, lokdb = 0; //a jelenleg vizsgált fa hányat dönt ki: addig növeljük míg dönti ki a fákat

    for (int i = 1; i < n; i++)
    {
        int tav = adatok[i].tav - adatok[lastmaxindex].tav;
        //ha nem dől ki
        if(adatok[lastmaxindex].mag <= tav)
        {
            db++;
            if(lokdb > maxe)
            {
                maxe = lokdb;
                maxi = loki;
            }
            loki = i;
            lokdb = 0;
        }
        else
        {
            lokdb++;
        }
        
        //ha a mostani tovább elér
        if(adatok[i].mag > adatok[lastmaxindex].mag - tav)
        {
            lastmaxindex = i;
        }
    }
    //utolsó fa is döntheti ki a legtöbbet
    if(lokdb > maxe)
    {
        maxe = lokdb;
        maxi = loki;
    }

    cout << db << endl;
    cout << maxi + 1 << endl;

    return 0;
}