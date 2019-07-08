#include <iostream>

using namespace std;

const int MAXN = 400000;

int main()
{
    int n, p;
    cin >> n >> p;
    int cnt[MAXN]; //cnt[i]: az i+1 ár utolsó előfordulása

    for (int i = 0; i < MAXN; i++)
    {
        cnt[i] = 0;
    }

    int a, b = 0;

    int i = 0;
    while (i < n && b == 0)
    {
        int be;
        cin >> be;
        int kell = p - be;
        if(kell > 0 && cnt[kell - 1] > 0) //ha előfordult már a hozzá tartozó pár
        {
            a = cnt[kell - 1];
            b = i + 1;
        }
        else
        {
            cnt[be - 1] = i + 1;
        }
        i++;
    }

    if(b != 0)
    {
        cout << a << " " << b;
    }
    else
    {
        cout << -1;
    }

    return 0;
}
