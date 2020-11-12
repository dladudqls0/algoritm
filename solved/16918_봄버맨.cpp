#include <iostream>
#include <queue>

using namespace std;
#define MAX 201

typedef struct{
    int arr[MAX][MAX];
    int row;
    int col;
    int time;
    queue <pair<int,int> > bomb_queue;
}map;

void insert(map*);
void printmap(map);
void even(map*);
void odd(map*);
void queueing(map*);

int main(void){
    map m1;
    insert(&m1);

    int time=1;
    while(time<m1.time){
        time++;
        if (time%2 ==0){
            even(&m1);
        }
        else{
            odd(&m1);
        }
    }

    printmap(m1);
    return 0;
}



void insert(map * m1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> m1->row >> m1->col >> m1->time;
    for(int i = 0; i< m1->row; i++){
        for(int j=0; j< m1->col; j++){
            char temp;
            cin >> temp;
            if(temp == '.')
                m1->arr[i][j]=-1;
            else if(temp== '0')
                m1->arr[i][j]=0;
        }
            
    }
}

void printmap(map m1){
    for(int i = 0; i< m1.row; i++){
        for(int j=0; j< m1.col; j++){
            int temp = m1.arr[i][j];
            if(temp == -1)
                cout<<'.';
            else if(temp== 0)
                cout<<'O';
        }
        cout<< endl;
    }
}

//map에 있는 모든 폭탄들을 큐에 넣어준다.
void queueing(map* m1){
    for(int i = 0; i< m1->row; i++){
        for(int j=0; j< m1->col; j++){
            int temp = m1->arr[i][j];
            if(temp == 0)
                m1->bomb_queue.push(make_pair(i,j));
        }
    }
}

//queueing을 하고, map을 모두 폭탄으로 채운다.
void even(map* m1){
    queueing(m1);
    for(int i = 0; i< m1->row; i++){
        for(int j=0; j< m1->col; j++)
            m1->arr[i][j] = 0;
    }
}

//큐에 있는 폭탄 터트린다.
void odd(map* m1){
    int dxdy[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    while(!m1->bomb_queue.empty()){
        int now_x= m1->bomb_queue.front().first;
        int now_y= m1->bomb_queue.front().second;
        m1->arr[now_x][now_y]=-1;

        for(int i=0; i<4; i++){
            int next_x = now_x + dxdy[i][0];
            int next_y = now_y + dxdy[i][1];
            if(next_x>=0 && next_x<m1->row && next_y >=0 && next_y < m1->col){
                m1->arr[next_x][next_y] = -1;
            }
        }
        m1->bomb_queue.pop();
    }
}
