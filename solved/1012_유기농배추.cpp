#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 51

typedef struct{
    int N;
    int M;
    int K;
    int arr[MAX][MAX];
}map;

void init(map * m1){
    memset(m1->arr,0,sizeof(m1->arr));
    cin >> m1->N >> m1->M >> m1->K;
    for(int i=0; i<m1->K; i++){
        int x;
        int y;
        cin >> x >> y;
        m1->arr[x][y]=1;
    }
}

int bfs(map m1){
    int visit[MAX][MAX];
    memset(visit,0,sizeof(visit));
    int count =0;
    for(int i=0; i<m1.N; i++){
        for(int j=0; j<m1.M; j++){
            if(m1.arr[i][j] == 1 && visit[i][j] == 0){
                visit[i][j]=1;
                count++;
                queue <pair<int,int> > q;
                q.push(make_pair(i,j));
                int dxdy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
                while(!q.empty()){
                    int now_x=q.front().first;
                    int now_y = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int next_x = now_x + dxdy[k][0];
                        int next_y = now_y + dxdy[k][1];
                        if(next_x>=0 && next_x < m1.N && next_y >=0 && next_y < m1.M){
                            if(visit[next_x][next_y]==0 && m1.arr[next_x][next_y]==1){
                                q.push(make_pair(next_x,next_y));
                                visit[next_x][next_y]=1;
                            }
                        }
                    }
                }
            }
            
        }
    }
    return count;
}

int main(void){
    int testcase;
    cin >> testcase;
    for(int i=0; i<testcase; i++){
        map m1;
        init(&m1);
        cout<< bfs(m1)<<endl;
    }
}

