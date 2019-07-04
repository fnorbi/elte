#include <iostream>
#include <cmath>

using namespace std;

int powerSum(int x, int n, int smallest)
{
    if(pow(smallest, n) < x)
    {
        //2 eset: vagy belevesszük vagy nem
        //ha belevesszük akkor kisebb szám az előállítandó, smallest nagyobb
        //ha nem akkor csak a smallest nagyobb
        return powerSum(x - pow(smallest, n), n, smallest + 1) + powerSum(x, n, smallest + 1);
    }
    else if(pow(smallest, n) == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int x, n;
    cin >> x;
    cin >> n;

    //3. paraméter: a legkisebb szám aminek hatványa szerepelhet az összegben
    int result = powerSum(x, n, 1);

    cout << result << endl;

    return 0;
}
