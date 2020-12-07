#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 1001

typedef struct {
    int N;
    int M;
    int V;
    vector <vector <int> > v;
}graph;
int visit[MAX];

void init(graph * g1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g1->N >> g1->M >> g1->V;


    for(int i=0; i<=g1->N; i++){
        vector <int> v1;
        g1->v.push_back(v1);
    }

    for(int j=0; j<g1->M; j++){
        int t1,t2;
        cin >> t1 >> t2;
        g1->v[t1].push_back(t2);
        g1->v[t2].push_back(t1);
    }
}

void dfs(graph g1, int now){
    visit[now]=1;

    cout<<now<<" ";
    
    for(int i=0; i<g1.v[now].size(); i++){
        int next = g1.v[now][i];
        if(visit[next]==0)
            dfs(g1,next);
    }
}

void bfs(graph g1){
    queue <int> q;
    q.push(g1.V);
    visit[g1.V]=1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout<<now<<" ";
        for(int i=0; i<g1.v[now].size(); i++){
            int next = g1.v[now][i];
            if(visit[next]==0){
                visit[next]=1;
                q.push(next);
            }
        } 
    }
    cout<<endl;
}


int main(void){
    graph g1;
    init(&g1);
    for(int i=1; i<=g1.N; i++){
        sort(g1.v[i].begin(),g1.v[i].end());
    }
    memset(visit,0,sizeof(visit));
    dfs(g1,g1.V);
    cout<<endl;
    memset(visit,0,sizeof(visit));
    bfs(g1);

    return 0;
}