#include <iostream>

using namespace std;

const int MAXN = 10000;

int main()
{
    int n, m;
    cin >> n >> m;
    bool a[MAXN];

    for (int i = 0; i < n; i++)
    {
        a[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        int k, v;
        cin >> k >> v;
        for (int j = k; j < v; j++)
        {
            a[j] = true;
        }
    }

    int db = 0;
    for (int i = 0; i < n; i++)
    {
        if(!a[i])
        {
            db++;
        }
    }
    
    cout << db << endl;

    return 0;
}
