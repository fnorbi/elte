//minden munkát a lehető legkésőbb kell elvégezni (amikor még lehet):
//határidőről haladunk visszafele, ha találunk neki napot akkor elvégezzük, ha nem akkor nem
#include <iostream>

using namespace std;

const int MAXN = 10000;
const int MAXH = 300;

int main()
{
    int n;
    cin >> n;
    int h[MAXN];

    for (int i = 0; i <= n; i++)
    {
        cin >> h[i];
    }

    int napok[MAXH + 1]; //napok[i]: az i-edik napon melyik munkát végezzük, 0 esetén szabadnap
    for (int i = 1; i <= MAXH; i++)
    {
        napok[i] = 0;
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int last = h[i];
        while(last > 0 && napok[last] > 0)
        {
            last--;
        }
        if(last > 0) //van szabad nap korábban, kiadható a munka
        {
            k++;
            napok[last] = i + 1;
        }
    }
    
    cout << k << endl;
    for (int i = 1; i <= MAXH; i++)
    {
        if(napok[i] > 0)
        {
            cout << napok[i] << " ";
        }
    }

    return 0;
}
