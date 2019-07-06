#include <iostream>

using namespace std;

const int MAXN = 10000;

int main()
{
    int n;
    cin >> n;
    int a[MAXN][7]; //a[i][j]: i. hét j. napja

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> a[i][j];
        }
    }

    int maxi = 0, maxe = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 7; j++)
        {
            sum += a[i][j];
        }
        if(sum > maxe)
        {
            maxi = i + 1;
            maxe = sum;
        }
    }
    
    cout << maxi << endl;

    return 0;
}
