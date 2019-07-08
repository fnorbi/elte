#include <iostream>

using namespace std;

int main()
{
    int n;
    int jegyek[5] = {0, 0, 0, 0, 0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        jegyek[x-1]++;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << jegyek[i] << " ";
    }
    
    return 0;
}