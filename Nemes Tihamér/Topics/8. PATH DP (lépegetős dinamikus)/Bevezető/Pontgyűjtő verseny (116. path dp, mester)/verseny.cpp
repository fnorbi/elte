//Oszloponként töltsük ki, végül egy sima maximum kiválasztás.
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct rec
{
    int e; //az érték ami maximálisan eléhető
    int index; //az index ahonnan a sora indult
};

int main()
{
    int n, m;
    cin >> n >> m;
    int a[MAXN][MAXN];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    rec opt[MAXN + 2][MAXN]; //az i+1. sor j+1. oszlopa, első 1-től, második dimenzió 0-tól indexel

    for (int i = 0; i < m; i++)
    {
        opt[0][i].e = -1;
        opt[n+1][i].e = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        opt[i][0].e = a[i-1][0];
        opt[i][0].index = i;
    }

    for (int j = 1; j < m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            opt[i][j].e = a[i-1][j];
            if(opt[i-1][j-1].e > opt[i][j-1].e && opt[i-1][j-1].e > opt[i+1][j-1].e) 
            {
                opt[i][j].e += opt[i-1][j-1].e;
                opt[i][j].index = opt[i-1][j-1].index;
            }
            else if(opt[i+1][j-1].e > opt[i][j-1].e)
            {
                opt[i][j].e += opt[i+1][j-1].e;
                opt[i][j].index = opt[i+1][j-1].index;
            }
            else 
            {
                opt[i][j].e += opt[i][j-1].e;
                opt[i][j].index = opt[i][j-1].index;
            }
        }
    }

    int maxi, maxe = -1;
    for (int i = 1; i <= n; i++)
    {
        if(opt[i][m-1].e > maxe)
        {
            maxe = opt[i][m-1].e;
            maxi = opt[i][m-1].index;
        }
    }
    
    cout << maxe << endl << maxi;

    return 0;
}
