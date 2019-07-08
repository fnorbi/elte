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
    int h[MAXN]; //ebbe a tömbbe olvasunk be folyamatosan

    int db = 0;
    int t[MAXN]; //ahová kiválogatunk

    for (int i = 0; i < n; i++)
    {
        bool volt = false;
        for (int j = 0; j < m; j++)
        {
            cin >> h[j];
            if(!volt) //ezt külön vizsgálva picit gyorsabb
            {
                if (j > 0 && !volt && abs(h[j-1] - h[j]) >= 10)
                {
                    volt = true;
                    t[db] = i + 1;
                    db++;
                }
            }
        }
    }

    cout << db << " ";
    for (int i = 0; i < db; i++)
    {
        cout << t[i] << " ";
    }

    return 0;
}
