/*
  Count arraybe jelzem, hogy melyik lépcső rossz. Rekurzív függvénnyel indulunk fentről le,
  ha leérünk találtunk egy újabb jó utat. Rossz lépcsőkre nem lépünk, figyelünk arra, hogy
  eddig hányszor léptünk és legfeljebb mekkorát léphetünk.
  Érdekesség: egy ciklus mentén hívunk meg sok rekurziót egyszerre.
 */
#include <iostream>

using namespace std;

const int MAXN = 100;

//n. lépcsőig kell felmenni, egyszerre legfeljebb k-t lépve, legfeljebb l-szer lépve
int rec(int n, int k, int l, bool t[MAXN])
{
    if (n == 0) //földszintre értünk, találtunk egy utat
    {
        return 1;
    }
    else if (l == 0) //nem léphetünk többet
    {
        return 0;
    }
    else
    {
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            if (n - i == 0 || n - i > 0 && t[n-i-1]) //ott még van lépcső és léphetünk is rá
            {
                sum += rec(n - i, k, l - 1, t);
            }
        }
        return sum;
    }
}

int main()
{
    int n, k, h, l;
    cin >> n >> k >> h >> l;

    bool t[MAXN]; //t[i] igaz ha az i+1. lépcsőre léphetünk
    
    for (int i = 0; i < n; i++)
    {
        t[i] = true;
    }
    
    //hibás lépcsőknél false-ra állítjuk
    for (int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        t[x-1] = false;
    }
    
    cout << rec(n, k, l, t);
    
    return 0;
}
