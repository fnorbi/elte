#include <iostream>

using namespace std;

const int MAXN = 1000;

struct interval
{
    int e, u;
};

int main()
{
    int m, n; //m nap, n őr
    cin >> m >> n;
    interval t[MAXN];

    int cnt[MAXN]; //cnt[i]: az i+1-edik napon hány őr volt
    for (int i = 0; i < MAXN; i++)
    {
        cnt[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].e >> t[i].u;
        for (int j = t[i].e; j <= t[i].u; j++)
        {
            cnt[j-1]++;
        }
    }

    //kiválogatjuk azokat a napokat ahol kevesebb mint 2 őr volt
    int db = 0;
    interval intervals[MAXN];
    int i = 0;
    while (i < m) //a napok száma m
    {
        if (cnt[i] < 2)
        {
            intervals[db].e = i + 1;
            int j = i + 1;
            while (j < m && cnt[j] < 2)
            {
                j++;
            }
            if (j < m)
            {
                intervals[db].u = j;
                i = j + 1;
            }
            else //különben az utolsó napig tart az intervallum
            {
                intervals[db].u = m;
                i = m;
            }
            db++;
        }
        else
        {
            i++;
        }
    }

    //maximumkiválasztás hossz szerint
    int maxi = 0, maxe = -1;
    for (int i = 0; i < db; i++)
    {
        if (intervals[i].u - intervals[i].e > maxe)
        {
            maxi = i;
            maxe = intervals[i].u - intervals[i].e;
        }
    }

    if (db == 0)
    {
        cout << 0;
    }
    else
    {
        cout << intervals[maxi].e << " " << intervals[maxi].u;
    }

    return 0;
}