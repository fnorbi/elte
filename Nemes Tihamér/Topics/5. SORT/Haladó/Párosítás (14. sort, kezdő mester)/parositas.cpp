#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

struct player
{
    int e; //erő
    int index; //eredeti index;
    bool np; //nincs párja
    bool operator < (player o)
    {
        return this -> e < o.e;
    }
};

int main()
{
    int n;
    cin >> n;
    player a[MAXN], b[MAXN];

    for (int i = 0; i < n; i++)
    {
        a[i].index = i + 1;
        cin >> a[i].e;
        //a[i].np = true;
    }
    for (int i = 0; i < n; i++)
    {
        b[i].index = i + 1;
        cin >> b[i].e;
        b[i].np = true;
    }
    
    sort(a, a + n); sort(b, b + n);

    int db = 0; //ahányat meg tudunk nyerni
    int answer[MAXN]; //a végül kiírandó választ tartalmazó tömb

    //sajátjainkon végighaladunk és a legkisebbhez megkeressük a legnagyobbat
    //akinél erősebb, ha nincs ilyen "feláldozzuk" és a legerősebbnek adjuk
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n && a[i].e > b[j].e)
        {
            j++;
        }
        if (j > 0) //van akinél erősebb, de olyan is van akinek még nincs párja?
        {
            int k = j - 1;
            while (k >= 0 && !b[k].np)
            {
                k--;
            }
            if (k >= 0) //olyan is van akinek még nincs párja
            {
                db++;
                answer[a[i].index - 1] = b[k].index;
                b[k].np = false;
            }
            else //akiknél erősebb azoknak mind van párja, legerősebbnek adjuk akinek még nincs párja
            {
                int k = n - 1;
                while (!b[k].np)
                {
                    k--;
                }
                answer[a[i].index - 1] = b[k].index;
                b[k].np = false;
            }
        }
        else //legerősebbnek adjuk akinek még nincs párja
        {
            int k = n - 1;
            while (!b[k].np)
            {
                k--;
            }
            answer[a[i].index - 1] = b[k].index;
            b[k].np = false;
        }
        i++;
    }

    cout << db << endl;
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
