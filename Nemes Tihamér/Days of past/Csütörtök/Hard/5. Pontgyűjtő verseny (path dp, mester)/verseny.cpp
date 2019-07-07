//Soronként sima maximumkiválasztás, dinamikus programozás a sorokon belül.
#include <iostream>

using namespace std;

const int MAXN = 100;

int main()
{
    int n, m;
    cin >> n >> m;
    int m[MAXN][MAXN];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> m[i][j];
        }
    }

    int maxi, maxe = -1;
    for (int i = 0; i < n; i++)
    {
        
    }
    
    cout << maxi << " " << maxe;

    return 0;
}
