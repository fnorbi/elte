#include <iostream>

using namespace std;

const int MAXN = 100;

int main()
{
    int n;
    cin >> n;
    int h[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

	int mine = h[0];
    for (int i = 0; i < n; i++)
    {
        if (h[i] < mine)
		{
			mine = h[i];
		}
    }
	
	cout << mine;

    return 0;
}