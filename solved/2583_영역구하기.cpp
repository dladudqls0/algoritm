#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 101

typedef struct {
    int M,N,K;
    int visit[MAX][MAX];
}paper;

void init(paper * p1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p1->M >> p1->N >> p1->K;
    memset(p1->visit,0,sizeof(p1->visit));

    for(int i=0; i<p1->K; i++){
        int temp[4];
        for(int j=0; j<4; j++){
            cin >> temp[j];
        }
        for(int k=temp[0]; k<temp[2]; k++){
            for(int l= temp[1]; l<temp[3]; l++){
                p1->visit[l][k]=1;
            }
        }

    }
}

int bfs(paper * p1, int r, int c){
    queue <pair<int,int> > q;
    int count=1;
    int dxdy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    q.push(make_pair(r,c));
    p1->visit[r][c]=1;
    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int next_x= now_x+dxdy[i][0];
            int next_y= now_y+dxdy[i][1];
            if(next_x>=0 && next_x<p1->M && next_y>=0 && next_y<p1->N){
                if(p1->visit[next_x][next_y]==0){
                    p1->visit[next_x][next_y]=1;
                    q.push(make_pair(next_x,next_y));
                    count++;
                }
            }
        }
    }
    return count;
}

void solve(paper * p1){
    vector <int> v; 
    for(int i=0; i<p1->M; i++){
        for(int j=0; j<p1->N; j++){
            if(p1->visit[i][j]==0){
                v.push_back(bfs(p1, i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    int temp = v.size();
    cout << temp << endl;
    for(int i=0; i<temp; i++){
        cout<< v[i] << " ";
    }
}

int main(void){
    paper p1;
    init(&p1);
    solve(&p1);
}