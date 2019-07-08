/*
    Short helyett a másik megoldás lehetne, hogy beolvasás közben csináljuk az eldöntéseket,
    és akkor csak egy 1000 hosszú tömböt tárolunk egy 1000x1000-es mátrix helyett.
*/
#include <iostream>
#include <cmath>

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

    int db = 0;
    int t[MAXN]; //ahová kiválogatunk

    for (int i = 0; i < n; i++)
    {
        //eldöntés
        int j = 0;
        while (j < m - 1 && abs(h[i][j] - h[i][j+1]) < 10)
        {
            j++;
        }
        if (j < m - 1)
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
