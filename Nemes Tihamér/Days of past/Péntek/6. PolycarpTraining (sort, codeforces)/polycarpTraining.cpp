#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

int main()
{
    int n;
    cin >> n;
    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int db = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] > db)
        {
            db++;
        }
    }

    cout << db << endl;
    
    return 0;
}
