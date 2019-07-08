#include <iostream>
//#include <algorithm>

using namespace std;

const int MAXN = 1000;

void swap(int &a, int &b)
{
    int s = a;
    a = b;
    b = s;
}

void bubbleSort(int n, int a[MAXN])
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bubbleSort(n, a);

    //sort(a, a + n);

    cout << a[(n-1)/2];

    return 0;
}
