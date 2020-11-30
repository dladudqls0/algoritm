#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int line[11]={0,};

    for(int i=0; i<n; i++){
        int temp,count=0;
        cin >> temp;
        for(int j=0; j<=temp+count; j++){
            if(line[j]!=0)
                count++;
        }
        line[temp+count]=i+1;
    }

    for(int i=0; i<n; i++){
        cout << line[i] << " ";
    }
    cout<<endl;
    return 0;
}