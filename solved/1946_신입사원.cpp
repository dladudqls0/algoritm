#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;

    cin >> testcase;
    for(int t=0; t<testcase; t++){
        int N;
        cin >> N;
        vector <pair<int, int> > v;
        for(int n=0; n<N; n++){
            int temp1,temp2;
            cin >> temp1 >> temp2;
            v.push_back(make_pair(temp1,temp2));
        }
        sort(v.begin(),v.end());

        int min=100001, count=0;
        for(int n=0; n<N; n++){
            if(v[n].second <min){
                min=v[n].second;
                count++;
            }
        }
        cout<<count<<endl;
    }
}
