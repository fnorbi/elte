#include <iostream>

using namespace std;

const int MAXN = 100000;

int main()
{
    int n, k;
    cin >> n >> k;
    int l[MAXN];

    for (int i = 0; i <= n; i++)
    {
        cin >> l[i];
    }

    int sum = l[0]; //aktuális szigetlakó összeg, ez kéne k legyen
    int i = 0, j = 1;
    /*
    while(j < n && sum < k) //találjuk meg az elsőt ahol nagyobb mint k
    {
        sum += l[j];
        j++;
    }
    */

    while(i < n - 1 && j < n && sum != k)
    {
        while(j < n && sum < k) //intervallum vég csúsztatása, növelés
        {
            sum += l[j];
            j++;
        }
        while(i < n - 1 && sum > k) //intervallum eleje csúsztatása, csökkentés
        {
            sum -= l[i];
            i++;
        }
    }

    if(sum == k)
    {
        cout << i + 1 << " " << j;
    }
    else
    {
        cout << -1;
    }
    
    return 0;
}
