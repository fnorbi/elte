#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int i = 0;
    while (i < a.size() && a[i] == b[i])
    {
        cout << a[i];
        i++;
    }
    cout << endl;
    int db = 0; //hol járunk b-ben
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[db])
        {
            db++;
            cout << a[i];
        }
    }
    return 0;
}