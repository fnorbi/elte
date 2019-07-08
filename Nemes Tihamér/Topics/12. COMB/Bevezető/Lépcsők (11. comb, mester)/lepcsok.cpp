/*
  Rekurzív függvénnyel indulunk fentről le, ha leérünk találtunk egy újabb jó utat.
  Érdekesség: egy ciklus mentén hívunk meg sok rekurziót egyszerre.

  Sima rekurzióval túl lassú, dinamikus programozással csináljuk!
*/
#include <iostream>

using namespace std;

const int MAXN = 100;

//n. lépcsőig kell felmenni, egyszerre legfeljebb k-t lépve
/*
int rec(int n, int k)
{
    if (n == 0) //földszintre értünk, találtunk egy utat
    {
        return 1;
    }
    else
    {
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            if (n - i >= 0) //ott még van lépcső vagy földszint
            {
                sum += rec(n - i, k);
            }
        }
        return sum;
    }
}
*/

int main()
{
    int n, k;
    cin >> n >> k;
    
    //cout << rec(n, k);

    //t[i] jelöli hogy az i. lépcsőfokra egyszerre legfeljebb k-t lépve hányféleképpen juthatunk
    int t[MAXN + 1];
    t[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        t[i] = 0;
        for (int j = 1; j <= k; j++)
        {
            if (i - j > 0) //ott még van lépcső
            {
                t[i] += t[i - j];
            }
            else if (i - j == 0)
            {
                t[j] += 1;
            }
        }
    }
    
    cout << t[n];

    return 0;
}
