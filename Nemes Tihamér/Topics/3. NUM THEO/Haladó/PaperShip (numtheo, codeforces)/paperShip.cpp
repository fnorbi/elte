#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    long long r;
    r = a % b;

    long long db = 0; //hány lépés alatt hajtódik végre az euklideszi algoritmus
    while(r != 0)
    {
        db += a / b; //annyi új készül ahányszor levágható b-ből az a
        a = b;
        b = r;
        r = a % b;
    }
    db += a / b; //az újak mikor már nincs maradék

    cout << db << endl;
    
    return 0;
}