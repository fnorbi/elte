//a mesternek elég az is ha int a mátrix
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 1000;

bool melegebb(int i, int j, int m, short h[MAXN][MAXN])
{
    int k = 0;
    while(k < m && h[i][k] > h[j][k])
    {
        k++;
    }
    return k >= m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    short h[MAXN][MAXN]; //h[i][j]: az i+1. település a j+1. napi hőmérséklete

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> h[i][j];
        }
    }

    int index = -1;
    bool van = false;

    int i = 0;
    while(i < n && !van)
    {
        int j = 0;
        while(j < n && !melegebb(i, j, m, h)) //melegebb-e az i a j-nél
        {
            j++;
        }
        if(j < n)
        {
            van = true;
        }
        i++;
    }

    if (van)
    {
        index = i;
    }
    
    cout << index;

    return 0;
}
