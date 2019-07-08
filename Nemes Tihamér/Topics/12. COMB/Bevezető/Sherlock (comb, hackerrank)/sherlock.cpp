#include <vector>
#include <map>
#include <iostream>
/**
 * https://www.hackerrank.com/challenges/sherlock-and-pairs/problem
 * Az eredeti környezet defektes volt, mind a string törés,
 * mind a függvény visszatérési értéke
 */

using namespace std;

unsigned long solve(const vector<int>& a) {
    map<int,unsigned long> m;
    for(int i: a){
        m[i]++;
    }
    unsigned long solution=0;
    for(auto b:m){
        solution+=b.second*(b.second-1);
    };
    return solution;
}

int main()
{
    int t;
    cin >> t;

    for (int j = 0; j < t; j++) {
        int a_count;
        cin >> a_count;
        vector<int> a(a_count);

        for (int i = 0; i < a_count; i++) {
            cin>>a[i];
        }
        cout << solve(a) << "\n";
    }

    return 0;
}