#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 101

typedef struct {
    int comNum;
    int connectNum;
    vector < vector<int> > v;
}network;

void init(network * n1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n1->comNum >> n1->connectNum;
    
    for(int i =0; i<= n1->comNum; i++){
        vector <int> temp;
        n1->v.push_back(temp);
    }

    for(int i=0; i<n1->connectNum; i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        n1->v[temp1].push_back(temp2);
        n1->v[temp2].push_back(temp1);
    }
}

int bfs(network n1){
    queue <int> q;
    q.push(1);
    int dest[MAX];
    memset(dest,0,sizeof(dest));
    dest[1]=1;
    int answer=0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<n1.v[now].size(); i++){
            int next = n1.v[now][i];
            if(dest[next]==0){
                q.push(next);
                dest[next]= 1;
                answer++;
            }
        }
    }
    return answer;
}

int main(void){
    network n1;
    init(&n1);
    cout<<bfs(n1)<<endl;
}