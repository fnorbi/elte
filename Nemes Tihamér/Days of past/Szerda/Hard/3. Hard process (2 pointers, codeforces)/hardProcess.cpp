#include <iostream>

using namespace std;

const int MAXN = 300000;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0, j = 0; //vándorló pointerek
    int vi = 0, vj = 0; //végleges pointerek
    int db = 0; //átírandókat számoljuk (meddig tudunk eljutni mohó módon)
    int z;

    while(db < k && j < n)
    {
        if(a[j] == 0)
        {
            db++;
        }
        j++;
    }

    while(a[j] == 1) //egyeseket jobboldalról még hozzávehetjük
    {
            j++;
    }

    vi = i; vj = j - 1;

    //eltoljuk az eddigit egy nullával -> az i-t kövi nulla mögé, j-t egy nulla elé
    //egyel eltolást korrigálni kell, j miatt bejött egy 0, i miatt nem biztos, hogy kiesett

    while(j < n)
    {
        //megyünk míg nincs i és j is 0-n (j automatikusan 0-n van)
        while(a[i] == 1)
        {
            i++;
        }
        i++; j++; //nulla elhagyása, hozzávétele
        while(a[j] == 1) //további hozzávehetőek jobbról
        {
            j++;
        }

        if(j - 1 - i > vj - vi) //ha végül nagyobb intervallumot kapok
        {
            vi = i; vj = j - 1;
        }
    }
    
    for(int i = vi; i <= vj; i++)
    {
        a[i] = 1;
    }

    z = vj - vi + 1;

    cout << z << endl;

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
