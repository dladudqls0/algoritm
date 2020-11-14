#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 201

typedef struct{
    int N;
    int K;
    int arr[MAX];
}belt;

void init(belt * b1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> b1->N >> b1->K;
    for(int i=0; i<b1->N*2; i++)
        cin >> b1->arr[i];
}

int solve(belt b1){
    int belt[MAX];
    int robot[MAX];
    memset(robot,0,sizeof(robot));
    for(int i=0; i<b1.N*2; i++)
        belt[i] = b1.arr[i];

    int time=0;

    //반복
    while(1){
        time++;
        int numOfZero=0;
        //first
        int temp = belt[b1.N*2-1];
        for(int i = b1.N*2 - 1; i>=0; i--){
            if(i-1<0)
                belt[i]=temp;
            else{
                belt[i] = belt[i-1];
                if(i<b1.N)
                    robot[i] = robot[i-1];
                    robot[i-1]=0;
            }
        }
        robot[b1.N-1]=0;

        //second
        for(int i = b1.N - 1; i>0; i--){
            if(belt[i]>0 && robot[i-1]==1 &&robot[i]==0){
                robot[i]=1;
                robot[i-1]=0;
                belt[i]--;
            }
        }

        //third
        if(belt[0]>0){
            robot[0]=1;
            belt[0]--;
        }
        
        //final
        for(int i = b1.N*2 - 1; i>=0; i--){
            if(belt[i]==0)
                numOfZero++;
        }

        if(numOfZero >= b1.K)
            break;
    }
    return time;
}

int main(void){
    belt b1;
    init(&b1);
    cout << solve(b1) <<endl;
}