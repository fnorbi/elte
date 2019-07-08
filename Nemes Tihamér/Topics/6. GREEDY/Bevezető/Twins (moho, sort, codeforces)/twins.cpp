#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int main()
{
    int n;
    cin >> n;
    int adatok[MAXN];
    //beolvasásnál számoljuk, hogy mennyi az összérték, a felénél többet akarok elvenni
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> adatok[i];
        sum += adatok[i];
    }

    sort(adatok, adatok + n, greater<int>());

    int got = 0; //addig veszem el, több mint a felét el nem vettem a nagy címleteknek
    int db = 0;
    while(2 * got <= sum)
    {
        got += adatok[db];
        db++;
    }

    cout << db;

    return 0;
}