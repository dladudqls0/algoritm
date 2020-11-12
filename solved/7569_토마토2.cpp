#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100

typedef struct {
    int r;
    int c;
    int h;
}q;

typedef struct {
    int arr[MAX][MAX][MAX];
    int row;
    int col;
    int height;
    int maxtime;
    queue <q> tomato;
}tomatoBox;

//입력받으며 queue에 토마토 넣기
void input(tomatoBox *box){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >>  box->col >> box->row >> box->height;
    for(int k=0; k<box->height; k++){
        for(int i =0; i<box->row; i++){
            for(int j=0; j<box->col; j++){
                int temp;
                cin >> temp;
                box->arr[i][j][k]= temp;
                if(temp == 1)
                    box->tomato.push({i,j,k});
            }
        }
    }
}


void BFS(tomatoBox * box){
    int dxdydz[6][3] = {{0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}, {0,0,1}, {0,0,-1}};
    while(!box->tomato.empty()){
        
        int now_x=box->tomato.front().r;
        int now_y=box->tomato.front().c;
        int now_z=box->tomato.front().h;
        
        box->maxtime = box->arr[now_x][now_y][now_z]-1;
        
        box->tomato.pop();
        
        for(int i=0; i<6; i++){
            int next_x = now_x + dxdydz[i][0];
            int next_y = now_y + dxdydz[i][1];
            int next_z = now_z + dxdydz[i][2];
            if(next_x>=0 && next_x<box->row && next_y >=0 && next_y < box->col && next_z>=0 && next_z<box->height){
                if(box->arr[next_x][next_y][next_z]==-1)
                    continue;
                else if(box->arr[next_x][next_y][next_z]==0){
                    box->tomato.push({next_x,next_y,next_z});
                    box->arr[next_x][next_y][next_z]=box->arr[now_x][now_y][now_z]+1;
                }
            }
        }
    }
    for(int k=0; k<box->height; k++){
        for(int i=0; i<box->row; i++){
            for(int j=0; j<box->col; j++){
                if(box->arr[i][j][k] == 0)
                box->maxtime=-1;
            }
        }
    }
}



int main(void){
    tomatoBox box;
    input(&box);
    BFS(&box);
    cout << box.maxtime << endl;
}
