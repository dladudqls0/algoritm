#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int count=0;
    while(1){
        int sum=0;
        count++;
        int L,P,V;
        cin >> L >> P >> V;
        if(L==0)
            return 0;
        
        sum += (V/P)*L;
        int temp = V%P;
        temp>L ? sum += L : sum += temp;


        cout << "Case "<<count<<": "<< sum <<endl;
    }
    return 0;
}