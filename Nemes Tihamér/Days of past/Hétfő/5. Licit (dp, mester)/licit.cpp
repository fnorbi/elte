#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

struct palyazat
{
    int a, b, f;
};

int main()
{
    int n, m;
    cin >> n >> m;
    palyazat t[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].a >> t[i].b >> t[i].f;
    }

    int nincsfed[MAXN]; //minden pályázatra az utolsó amivel nincs fedésben (új index szerint)
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        while(j > -1 && t[j].b >= t[i].a)
        {
            j--;
        }
        if(j > -1)
        {
            nincsfed[i] = j;
        }
        else
        {
            nincsfed[i] = -1; //-1 jelöli ha minden korábbival fedésben van
        }
    }
    
    int opt[MAXN + 1]; //m[i]: az első i pályázatból mennyi lenne a max pénz
    opt[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if(t[i-1].f + opt[nincsfed[i-1]+1] > opt[i-1]) //indexekkel vigyázni, nincsfed 0-tól indexel
        {
            //cout<<i<<" ";
            opt[i] = t[i-1].f + opt[nincsfed[i-1]+1];
        }
        else
        {
            opt[i] = opt[i-1];
        }
    }
    
    //kiválogatom a jó pályázatokat: ha változik az összeg akkor az egy jó pályázat volt,
    //ekkor az előtte levő, vele fedésben nem levőtől folytatom
    int db = 0;
    int jo[MAXN];
    int i = n;
    while(i > 0)
    {
        if(opt[i] == opt[i-1])
        {
            i--;
        }
        else
        {
            jo[db] = i;
            db++;
            i = nincsfed[i-1]+1;
        }
    }

/*
    for (int i = 0; i < n; i++)
    {
        cout<<t[i].index<<" "<<t[i].a<<" "<<t[i].b<<" "<<t[i].f<<endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<nincsfed[i]<<" ";
    }

    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << opt[i] << " ";
    }
    
    cout << endl;
*/

    cout << opt[n] << endl;

    cout << jo[db - 1];
    for (int i = db - 2; i >= 0; i--)
    {
        cout << " " << jo[i];
    }
    cout << endl;
    
    return 0;
}
