/*
Balról indítom a pointereket, j-vel megyek amíg i-hez lezárást nem találok.
Ekkor kaptam egy jó intervallumot (ha j < n). Elcsúsztatom az i-t és hozzá
keresek új j-t (i + 1 -től amíg j < n).
"Végig" kell menni: i felső határa n-1.
Ha találok j - i - 1 < mostani optimum (v - k) akkor átírom azokat.
 */
#include <iostream>

using namespace std;

const int MAXN = 20000;

int main()
{
    int n, h;
    cin >> n >> h;
    int a[MAXN];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k = 0, v = 0;
    int hajo = 0; //hajó aktuális mennyisége

    //első intervallum keresése
    int j = 0;
    while(j < n && hajo < h)
    {
        hajo += a[j];
        j++;
    }
    if(hajo >= h) //van jó intervallum
    {
        k = 1;
        v = j;
        for (int i = 1; i < n - 1; i++) //keressünk jobbat, egyet lép i, meddig kell vinni j-t?
        {
            hajo = a[i]; //i lesz az intervallum elje, a[i] van a hajóban
            j = i + 1;
            while(j < n && hajo < h)
            {
                hajo += a[j];
                j++;
            }
            if(hajo >= h && j - i - 1 < v - k)
            {
                k = i + 1; v = j;
            }
        }
        cout << k << " " << v;
    }
    else
    {
        cout << -1;
    }

    return 0;
}
