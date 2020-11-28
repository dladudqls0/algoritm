#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;



int main(void){
    string s1;
    string s2="";
    vector <int> v;
    cin >> s1;

    for(int i=0; i<=s1.size(); i++){
        if(s1[i] =='+' || s1[i] =='-'|| s1[i] =='\0'){
            if(i!=0){
                v.push_back(stoi(s2));
                s2="";
            }
        }
        s2 += s1[i];
    }
    int sum=0;
    int minus=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]<0)
            minus=1;
            
        if(minus==0){
            sum+=v[i];
        }
        else{
            sum-=abs(v[i]);
        }
    }

    cout<< sum <<endl;
}
