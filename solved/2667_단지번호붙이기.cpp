#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;   
#define MAX 25

typedef struct {
    int N;
    char arr[MAX][MAX];
    int visit[MAX][MAX];
    int numofGroup;
    vector <int> numofHouse;
}map;

void initMap(map*);
void solve(map*);
int bfs(map*, int, int);
void printAnswer(map);

int main(void){
    map m1;
    initMap(&m1);
    solve(&m1);
    printAnswer(m1);
    return 0;
}


void initMap(map *m1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m1->N;
    for(int i=0; i< m1->N; i++){
        for(int j=0; j<m1->N; j++){
            char temp;
            cin >> temp;
            m1->arr[i][j]=temp;
            m1->visit[i][j]=0;
        }
    }
    m1->numofGroup=0;
}

void solve(map * m1){
    for (int i = 0; i< m1->N; i++){
        for( int j=0; j< m1->N; j++){
            if(m1->arr[i][j]=='1' && m1->visit[i][j] == 0){
                int temp = bfs(m1, i, j);
                m1->numofGroup++;
                m1->numofHouse.push_back(temp);
            }
        }
    }
    sort(m1->numofHouse.begin(),m1->numofHouse.end());
}

int bfs(map * m1, int x, int y){
    int num=0;
    queue <pair<int, int> > q;
    int dxdy[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    q.push(make_pair(x,y));
    m1->visit[x][y]=1;

    while(!q.empty()){
        int now_x= q.front().first;
        int now_y= q.front().second;
        num++;
        q.pop();
        for(int i=0; i<4; i++){
            int next_x = now_x+dxdy[i][0];
            int next_y = now_y+dxdy[i][1];
            if(next_x>=0 && next_x<m1->N && next_y>=0 && next_y<m1->N){
                if(m1->visit[next_x][next_y]==0 && m1->arr[next_x][next_y]=='1'){
                    q.push(make_pair(next_x,next_y));
                    m1->visit[next_x][next_y]=1;
                }
                    
            }
        }
    }
    return num;
}

void printAnswer(map m1){
    cout<<m1.numofGroup<<endl;
    for(int i=0; i<m1.numofHouse.size(); i++)
        cout<<m1.numofHouse[i]<<endl;
}