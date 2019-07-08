#include <iostream>

using namespace std;

const int MAXN = 10000;

struct rect
{
    int a, b;
};

int main()
{
    int n;
    cin >> n;
    rect a[MAXN];

    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b;
        sum += a[i].a * a[i].b;
    }

    cout << sum << endl;

    return 0;
}
