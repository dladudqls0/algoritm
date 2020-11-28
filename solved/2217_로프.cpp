#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> v;
    int max = -1;

    int N, temp;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    
    for(int i=0; i<N; i++){
        int t1 = v[i]*(N-i);
        if(t1>max)
            max=t1;
    }
    
    


    cout << max << endl;
}