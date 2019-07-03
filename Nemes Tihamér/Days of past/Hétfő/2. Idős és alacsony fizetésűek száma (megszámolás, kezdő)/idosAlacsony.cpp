#include <iostream>

using namespace std;

const int MAXN = 100;

struct ember
{
    int kor, fizetes;
};

int main()
{
    int n, l, m;
    cin >> n >> l >> m;
    ember adatok[MAXN];
    int db = 0;
    for (int i = 0; i < n; i++)
    {
        int kor, fizetes;
        cin >> kor >> fizetes;
        adatok[i].kor = kor;
        adatok[i].fizetes = fizetes;
        
        if(kor > l && fizetes < m)
        {
            db++;
        }
    }

    cout << db;
    
    return 0;
}