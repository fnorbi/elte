/*
    Biztosan előállítható minden az 1-es miatt. Ha az első i darab előállítható max
    m darabbal akkor i+1 is m+1 darabbal, van-e jobb ennél?
    Dinamikus programozás K szerint haladva.
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200;
const int MAXK = 100000;
int t[MAXK + 1];

int main()
{
    int n, k;
    cin >> n >> k;
    int a[MAXN];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //int t[MAXK+1]; //t[i]: az első i szám legalább ennyi darabbal állítható elő
    //nekünk most max t[i] kell
    t[0] = 0;
    t[1] = 1;

    for (int i = 0; i < n; i++)
    {
        t[a[i]] = 1;
    }

    for (int i = 2; i <= k; i++)
    {
        if (t[i] == 1)
        {
            continue;
        }
        t[i] = t[i-1] + 1; //m+1 darabbal biztosan előáll
        int j = 1;
        //összes pénzre megnézzük, hogy ha vele fizetnénk ki az elsőt akkor mennyi kellene még
        //minimumkiválasztás
        while (j < n && i - a[j] > 0)
        {
            if (t[i-a[j]] + 1 < t[i])
            {
                t[i] = t[i-a[j]] + 1;
            }
            j++;
        }
    }

    cout << *max_element(t, t + k + 1);

    return 0;
}
