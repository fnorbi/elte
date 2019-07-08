#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N,K;

/**
 * https://www.hackerrank.com/challenges/consecutive-subsequences/problem
 * Működik de túl lassú
 */


uint64_t solve(const vector<int>& dat){
    uint64_t solution=0;
    int base=0;
    vector<int> tmp(dat.size(),0);
    for(int i=0;i<dat.size();i++){
        for(int j =0;j<dat.size()-i;j++){
            int akt=(tmp[j]+dat[i+j])%K;
            tmp[j]=akt;
            if(akt==0)solution++;
        }
    }

    return solution;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N>>K;
        vector<int> dat(N);
        uint64_t solution=0;
        for(int j=0;j<N;j++){
            int tmp;
            cin>>tmp;
            dat[j]=tmp%K;
          //  if(tmp%K==0)solution++;
        }
        
        solution=solve(dat);
        cout<<solution<<'\n';
    }
    return 0;

}
