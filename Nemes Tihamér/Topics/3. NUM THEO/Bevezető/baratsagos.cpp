#include <iostream>
#include <cmath>

using namespace std;

//kivéve n-t, mert barátságosokat keresünk, sigmában amúgy benne lenne
int sigma(int n)
{
    //osztó találása esetén vele és osztópárjával is növeljük a sum-ot
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)
        {
            sum += i;
            sum += n/i;
        }
    }
    int a = (int) sqrt(n);
    if (a * a == n) //ha négyzetszám akkor a gyöke egész, osztja n-et
    {
        sum += a;
    }

    return sum;
}

int main()
{
    long long n;
    cin >> n; //futtatás: 500 000 -ig gyors, 1 500 000 -ig kivárható kb.

    //cout<< sigma(n);

    for (int i = 3; i <= n; i++)
    {
        int a = sigma(i);
        if (a <= n) //ez elhagyható, de akkor a számpár második tagja túlfuthat n-en
        {
            int b = sigma(a);
            if (b == i && i < a)
            {
                cout << i << " " << a << endl;
            }
        }
    }

    return 0;
}