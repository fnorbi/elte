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

    int i = 0;
    while (i < n && h[i] > 0)
    {
        i++;
    }
    
    if (i < n)
    {
        cout << i + 1;
    }
    else
    {
        cout << -1;
    }
    return 0;
}