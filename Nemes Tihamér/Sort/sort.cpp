#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rec
{
	string name;
    int age;
    //Rendezési reláció definiálása
    bool operator<(const rec o) const
    {
        return this->age < o.age;
    }
};

void kiir(vector<rec> adatok)
{
    for(auto r : adatok)
    {
        cout<<r.name<<" "<<r.age<<endl;
    }
}

int main()
{
    setlocale(LC_ALL,"hu");

    int n;
    vector<rec> adatok;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        rec x;
        cin>>x.name>>x.age;
        adatok.push_back(x);
    }

    kiir(adatok);
    cout<<endl;

    sort(adatok.begin(), adatok.end());
    //sort(adatok.rbegin(), adatok.rend()); //right begin

    kiir(adatok);

	return 0;
}
