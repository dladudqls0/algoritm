#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MIN 987654321

typedef struct Map{
    int arr[21][21];
    int size;
}map;

typedef struct Fish{
    int x;
    int y;
    int dist;
}fish;

typedef struct Shark{
    int x;
    int y;
    int size;
    int exp;
}shark;

//먹을 물고기를 찾아주고 없으면 distance에 -1을 반환한다.
fish bfs(map m1, shark babyShark){
    int dxdy[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
    int dist[21][21];

    fish eatfish;
    int eat_dist=MIN;
    vector <pair <int, int> > Eat;

    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++)
            dist[i][j]=0;
    }

    queue<pair<int,int> > q;
    q.push(make_pair(babyShark.x,babyShark.y));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int next_x = x+dxdy[i][0];
            int next_y = y+dxdy[i][1];

            //next_x,next_y가 잘못됐으면 안댐
            if(0>next_x || m1.size <= next_x || 0>next_y || m1.size<= next_y)
                continue;

            //이동은 상어랑 크기가 작거나 같아야 할 수 있음
            if(dist[next_x][next_y] == 0 && babyShark.size >= m1.arr[next_x][next_y]){
                dist[next_x][next_y] = dist[x][y]+1;

                //자기보다 작은 물고기 있을 때
                if(m1.arr[next_x][next_y]>0 && m1.arr[next_x][next_y] < babyShark.size ){
                    //최소거리에 있는 물고기?
                    if(eat_dist >= dist[next_x][next_y]){
                        eat_dist=dist[next_x][next_y];
                        Eat.push_back(make_pair(next_x,next_y));
                    }
                }
                q.push(make_pair(next_x,next_y));
            }
        }
        
    }
    if(eat_dist != MIN){
        sort(Eat.begin(),Eat.end());
        eatfish.x=Eat[0].first;
        eatfish.y=Eat[0].second;
    }
    eatfish.dist=eat_dist;

    return eatfish;
}







int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int time=0;

    //상어
    shark babyShark;
    babyShark.size=2;
    babyShark.exp=0;

    map m1;
    //맵 크기
    int yap;
    cin >> yap;
    m1.size=yap;

    //2차원 배열 입력받기
    for(int i=0; i<m1.size; i++){
        for(int j =0; j<m1.size; j++){
            cin >> m1.arr[i][j];
            if (m1.arr[i][j] == 9){
                m1.arr[i][j] = 0;
                babyShark.x=i;
                babyShark.y=j;
            }
        }
    }


    while(1){
        fish temp = bfs(m1, babyShark);
        if (temp.dist == MIN)
            break;
        else{
            //물고기를 잡아 먹는다.
            time += temp.dist;
            babyShark.x = temp.x;
            babyShark.y = temp.y;
            m1.arr[temp.x][temp.y]=0;

            babyShark.exp++;
            if(babyShark.exp == babyShark.size){
                babyShark.exp=0;
                babyShark.size++;
            }
        }
    }
    
    cout << time << endl;
    return 0;
}