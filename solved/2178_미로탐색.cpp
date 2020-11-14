#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 101

typedef struct {
    int N;
    int M;
    int arr[MAX][MAX];
}map;

void init(map * m1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> m1->N >> m1->M;
    for(int i =0; i<m1->N; i++){
        for(int j=0; j<m1->M; j++){
            char temp;
            cin >> temp;
            if(temp == '0'){
                m1->arr[i][j]=0;
            }
            else{
                m1->arr[i][j]=1;
            }
        }
    }
}


int bfs(map m1){
    int dxdy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int visit[MAX][MAX];
    memset(visit,0,sizeof(visit));
    queue <pair<int, int> > q;
    visit[0][0]=1;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int now_x=q.front().first;
        int now_y=q.front().second;
        q.pop();
        if(now_x==m1.N-1 && now_y==m1.M-1)
            return visit[now_x][now_y];
        for(int i=0; i<4; i++){
            int next_x = now_x + dxdy[i][0];
            int next_y = now_y + dxdy[i][1];
            if(next_x>=0 && next_x<m1.N && next_y>=0 && next_y<m1.M){
                if(m1.arr[next_x][next_y]==1 && visit[next_x][next_y]==0){
                    visit[next_x][next_y]=visit[now_x][now_y]+1;
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
    }
    return -1;
}

int main(void){
    map m1;
    init(&m1);
    cout<<bfs(m1)<<endl;
    return 0;
}
