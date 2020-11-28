#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 11

typedef struct{
    vector <pair<int, int> > v;
    int N;
}meeting;

void init(meeting * m1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m1->N;
    for(int i=0; i< m1->N; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        m1->v.push_back(make_pair(temp2,temp1));
    }
    sort(m1->v.begin(),m1->v.end());
}

int solve(meeting m1){
    int temp = m1.v[0].first;
    int count = 1;
    for(int i=1; i<m1.N; i++){
        int t1 = m1.v[i].second;
        if(t1>= temp){
            temp= m1.v[i].first;
            count++;
        }
    }
    return count;
}

int main(void){
    meeting m1;
    init(&m1);
    cout << solve(m1) << endl;
}