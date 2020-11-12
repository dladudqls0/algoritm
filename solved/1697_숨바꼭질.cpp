#include <iostream>
#include <queue>
#include <cstring>

using namespace std;   
#define MAX 100001


int bfs(int N, int K){
    int time[MAX];
    memset(time,0,sizeof(time));
    queue <int> q;
    q.push(N);

    while(!q.empty()){
        int now = q.front();
        q.pop();


        for(int i=0; i<3; i++){
            int next;
            if(i == 0)
                next=now+1;
            else if (i == 1)
                next=now-1;
            else
                next=now*2;

            if (next<MAX && next>=0 && time[next]==0){
                q.push(next);
                time[next] = time[now]+1;
            }
        }
        if(now == K)
            return time[now];
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    cout << bfs(N,K) << endl;
    return 0;
}