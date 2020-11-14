#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 1001

typedef struct{
    int N;
    int M;
    vector <vector <int> > v;
}graph;


void init(graph * g1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> g1->N >> g1->M;
    for(int i=0; i<=g1->N; i++){
        vector <int> temp;
        g1->v.push_back(temp);
    }

    for(int i=0; i<g1->M; i++){
        int t1, t2;
        cin >> t1 >> t2;
        g1->v[t1].push_back(t2);
        g1->v[t2].push_back(t1);
    }
}

int bfs(graph g1){
    int visit[MAX];
    memset(visit,0,sizeof(visit));
    int count = 0;
    for(int i=1; i<=g1.N; i++){
        if(visit[i]==0){
            count++;
            queue <int> q;
            visit[i]=1;
            q.push(i);

            while(!q.empty()){
                int now = q.front();
                q.pop();
                for(int j=0; j<g1.v[now].size(); j++){
                    int next = g1.v[now][j];
                    if(visit[next]==0){
                        q.push(next);
                        visit[next]=1;
                    }
                }
            }
        }
    }
    return count;
}

int main(void){
    graph g1;
    init(&g1);
    cout << bfs(g1) <<endl;
    return 0;
}