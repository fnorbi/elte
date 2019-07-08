#include <iostream>

using namespace std;

const int MAXN = 10000;

int main()
{
    int n, h;
    cin >> n >> h;
    int r[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }

    int m = 0; //ahány eszköz kell
    int numbers[MAXN]; //a házak indexei ahová kellenek
    int lastpoz; //az utolsó hely ahová került
    int first = 0; //az első hely ahová most nem ér el

    int i = 0;
    while(i < n)
    {
        //tegyük amilyen messzire lehet
        while(i < n && r[i] <= r[first] + h)
        {
            i++;
        }
        lastpoz = r[i-1];
        numbers[m] = i;
        m++;
        while(i < n && r[i] <= lastpoz + h)
        {
            i++;
        }
        first = i; //ő "jobbról" kell majd wifit kapjon
    }
    
    cout << m << endl;

    for (int i = 0; i < m; i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
