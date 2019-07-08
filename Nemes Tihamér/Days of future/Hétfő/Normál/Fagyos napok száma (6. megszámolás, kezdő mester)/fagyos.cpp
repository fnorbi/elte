#include <iostream>

using namespace std;

const int MAXN = 100;

int main()
{
    int n;
    cin >> n;
    int h[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int db = 0;
    for (int i = 0; i < n; i++)
    {
        if(h[i] < 0)
        {
            db++;
        }
    }

    cout << db;

    return 0;
}