#include <iostream>

using namespace std;

const int MAXN = 100;

string gameOfStones(int n)
{
    bool m[MAXN + 1]; //m[i]: a következő játékos nyerne-e i kavics esetén?

    m[0] = false;
    m[1] = false;
    m[2] = true;
    m[3] = true;
    m[4] = true;

    for (int i = 5; i <= n; i++)
    {
        m[i] = !m[i-2] || !m[i-3] || !m[i-5];
    }

    if(m[n])
    {
        return "First";
    }
    else
    {
        return "Second";
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string result = gameOfStones(n);

        cout << result << "\n";
    }

    return 0;
}
