#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1001

typedef struct {
    int arr[MAX][MAX];
    int row;
    int col;
    int maxtime;
    queue <pair<int,int> > tomato;
}tomatoBox;

//입력받으며 queue에 토마토 넣기
void input(tomatoBox *box){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >>  box->col >> box->row;
    for(int i =0; i<box->row; i++){
        for(int j=0; j<box->col; j++){
            int temp;
            cin >> temp;
            box->arr[i][j]= temp;
            if(temp == 1)
                box->tomato.push(make_pair(i,j));
        }
    }
}


void BFS(tomatoBox * box){
    int dxdy[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    while(!box->tomato.empty()){
        
        int now_x=box->tomato.front().first;
        int now_y=box->tomato.front().second;
        box->maxtime = box->arr[now_x][now_y]-1;
        
        box->tomato.pop();
        
        for(int i=0; i<4; i++){
            int next_x = now_x + dxdy[i][0];
            int next_y = now_y + dxdy[i][1];
            if(next_x>=0 && next_x<box->row && next_y >=0 && next_y < box->col){
                if(box->arr[next_x][next_y]==-1)
                    continue;
                else if(box->arr[next_x][next_y]==0){
                    box->tomato.push(make_pair(next_x,next_y));
                    box->arr[next_x][next_y]=box->arr[now_x][now_y]+1;
                }
            }
        }
    }

    for(int i=0; i<box->row; i++){
        for(int j=0; j<box->col; j++){
            if(box->arr[i][j] == 0)
                box->maxtime=-1;
        }
    }
}



int main(void){
    tomatoBox box;
    input(&box);
    BFS(&box);
    cout << box.maxtime << endl;
}

