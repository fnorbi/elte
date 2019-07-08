//Valójában ez a Fibonacci sorozat egyel eltoltja.
#include <iostream>

using namespace std;

const int MAXN = 80;

long long fib(int n)
{
    if(n > 2)
    {
        return fib(n-2) + fib(n-1);
    }
    else if(n == 2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);

    return 0;
}
