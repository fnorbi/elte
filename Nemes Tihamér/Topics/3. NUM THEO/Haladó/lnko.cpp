#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    long long q, r;
    q = a / b;
    r = a % b;

    while(r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    cout << q << endl;
    
    return 0;
}