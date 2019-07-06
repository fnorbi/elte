#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

/**
 * A legocsmányabb megoldás, de legalább nem rekurzív.
 * 
 */

int main(){
    int N, mo[8];
    cin>>N;
    for ( mo[0] = 0; mo[0] < 3; mo[0]++)
    {
        for ( mo[1] = 0; mo[1] < 3; mo[1]++)
        {
            for ( mo[2] = 0; mo[2] < 3; mo[2]++)
            {
                for ( mo[3] = 0; mo[3] < 3; mo[3]++)
                {
                    for ( mo[4] = 0; mo[4] < 3; mo[4]++)
                    {
                        for ( mo[5] = 0; mo[5] < 3; mo[5]++)
                        {
                            for ( mo[6] = 0; mo[6] < 3; mo[6]++)
                            {
                                for ( mo[7] = 0; mo[7] < 3; mo[7]++)
                                {
                                    vector<int>akt;
                                    akt.push_back(1);
                                    for(int i=0;i<8;i++){
                                        if(mo[i]==0){
                                            if(akt.back()>0){
                                                akt.back()=akt.back()*10+i+2;
                                            }else{
                                                akt.back()=akt.back()*10-i-2;
                                            }
                                        }else if(mo[i]==1){
                                            akt.push_back(i+2);
                                        }else if(mo[i]==2){
                                            akt.push_back(-i-2);
                                        }
                                    }
                                    if(accumulate(akt.begin(),akt.end(),0)==N){
                                        string mo="";
                                        for(int i:akt)mo+=(i>0?"+"+to_string(i):to_string(i));
                                        cout<<mo.erase(0,1);
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }   
            }
        }
    }

/**
 * Aki a tesztelő rendszert írta nem normális
 * cout<<"LEHETETLEN";
 * cout<<"LEHETETLEN"<<'\n';
 * nem működik erre pazaroltam el több mint egy órát...
 */
    cout<<"LEHETETLEN"<<endl;
    return 0;
}