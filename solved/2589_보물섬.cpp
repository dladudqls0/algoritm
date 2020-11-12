#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 51

char map[MAX][MAX];

int BFS(int x, int y, int n, int m){
    int max_length = -1;
    int visit[MAX][MAX]={0, };
    int dist[MAX][MAX]={0, };
    visit[x][y]=1;
    int dxdy[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    queue <pair<int,int> > q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i =0; i <4; i++){
            int next_x= now_x + dxdy[i][0];
            int next_y= now_y + dxdy[i][1];
            if(next_x < 0 || next_y< 0 || next_x >= n || next_y >= m)
                continue;
            if(visit[next_x][next_y]==0 && map[next_x][next_y]=='L'){
                visit[next_x][next_y] = 1;
                dist[next_x][next_y] = dist[now_x][now_y]+1;
                max_length = dist[next_x][next_y];
                
                q.push(make_pair(next_x,next_y));
            }
        }
    }
    return max_length;
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    int max_dist= 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 'W')
                continue;
            int temp = BFS(i,j,N,M);
            if( max_dist < temp )
                max_dist = temp;
        }
    }
    
    cout << max_dist << endl;
}