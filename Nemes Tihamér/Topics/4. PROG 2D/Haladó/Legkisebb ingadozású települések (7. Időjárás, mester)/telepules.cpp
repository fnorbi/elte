#include <iostream>

using namespace std;

const int MAXN = 1000;

int main()
{
    int n, m;
    cin >> n >> m;
    short h[MAXN][MAXN]; //h[i][j]: az i+1. településen a j+1. napi hőmérséklete

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> h[i][j];
        }
    }

    int diff[MAXN]; //diff[i]: az i+1. településen a legnagyobb és legkisebb hőmérséklet különbség
    for (int i = 0; i < n; i++)
    {
        int maxe = -51, mine = 51;
        for (int j = 0; j < m; j++)
        {
            if(h[i][j] > maxe) maxe = h[i][j];
            if(h[i][j] < mine) mine = h[i][j];
        }
        diff[i] = maxe - mine;
    }

    //minimumkiválasztás
    int mindiff = diff[0]; //-végtelen lehetne: INT_MIN
    for (int i = 1; i < n; i++)
    {
        if (diff[i] < mindiff)
        {
            mindiff = diff[i];
        }
    }
    
    //kiválogatás, előre kell tudnunk hány van, különben már itt is ki lehetne írni az indexeket
    int db = 0;
    int t[MAXN];
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == mindiff)
        {
            t[db] = i + 1;
            db++;
        }
    }
    
    cout << db << " ";
    for (int i = 0; i < db; i++)
    {
        cout << t[i] << " ";
    }
    
    return 0;
}
