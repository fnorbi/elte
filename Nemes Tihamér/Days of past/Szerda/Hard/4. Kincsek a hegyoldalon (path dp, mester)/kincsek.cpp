//Minden gyűjtőhelyre megnézzük, hogy oda hány kincset lehet elvinni (dp), ezekből maximumszámolás.
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

struct poz
{
    int ert; //értéke
    bool gyujto; //gyűjtőpont-e?
};

int main()
{
    int n, m, k, g;
    cin >> n >> m >> k >> g;
    poz mat[MAXN + 1][MAXN + 1]; //m[i][j].ert jelöli, hogy az (i,j) helyig hány kincs gyűjthető

    //alap esetben semmi sem gyűjtő, sehol sincs kincs

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            mat[i][j].ert = 0;
            mat[i][j].gyujto = false;
        }
    }

    //kincsek és gyűjtőhelyek lepakolása

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y].ert = 1;
    }

    for (int i = 0; i < g; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x][y].gyujto = true;
    }
    
    int maxe = -1; //maximálisan begyűjthető kincsek száma;
    int maxi = -1, maxj = -1; //indexei

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(mat[i-1][j].gyujto && mat[i][j-1].gyujto) mat[i][j].ert = -1; //ide el se tudunk jutni
            else if(mat[i-1][j].gyujto) mat[i][j].ert += mat[i][j-1].ert;
            else if(mat[i][j-1].gyujto) mat[i][j].ert += mat[i-1][j].ert;
            else
            {
                if(mat[i-1][j].ert > mat[i][j-1].ert)
                {
                    mat[i][j].ert += mat[i-1][j].ert;
                }
                else
                {
                    mat[i][j].ert += mat[i][j-1].ert;
                }
            }
            
            if(mat[i][j].gyujto && mat[i][j].ert > maxe) //maximum kiválasztás
            {
                maxe = mat[i][j].ert;
                maxi = i;
                maxj = j;
            }
        }
    }

    cout << maxe << endl;
    if (maxe != 0)
    {
        cout << maxi << " " << maxj;
    }
    
    return 0;
}
