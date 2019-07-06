//Egy konténerben lévő elemek súlya legfeljebb annak minimuma + 4:
//range(min, min + 4)-be esnek az elemek
// sort + új konténer ha túllépünk a határon
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int main()
{
    int n;
    cin >> n;
    int w[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    sort(w, w + n);

    int db = 1;
    int min = w[0];

    for (int i = 1; i < n; i++)
    {
        if(w[i] > min + 4)
        {
            db++;
            min = w[i];
        }
    }

    cout << db << endl;

    return 0;
}
