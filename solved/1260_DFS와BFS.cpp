#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Graph{
    int dot_num;
    int line_num;
    int start_dot;
    int arr[1001][1001];
    char visit[1001];
}graph;


void DFS(graph *g1, int now){
    g1->visit[now] = 1;
	cout << now << " ";
	for (int i = 1; i <= g1->dot_num; i++) {
        if ( i == now )
            continue;
        else if (g1->visit[i] == 0 && g1->arr[now][i] == 1 )
            DFS(g1,i);
	}
}



void BFS(graph *g1, int now){
    queue<int> q;
    g1->visit[now]=1;
    q.push(now);

    while(!q.empty()){
        now = q.front();
        q.pop();

        cout << now << " ";
        for(int i = 1; i<= g1->dot_num; i++){
            if(g1->visit[i] == 0 && g1->arr[now][i] == 1){
                q.push(i);
                g1->visit[i]=1;
            }
        }
    }
}


graph input(void){
    graph g1;
    int N, M, V;
    cin >> N >> M >> V ;
    g1.dot_num = N;
    g1.line_num = M;
    g1.start_dot = V;
    for (int i=0; i< M; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        g1.arr[temp1][temp2] = 1;
        g1.arr[temp2][temp1] = 1;
    }

    return g1;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //graph 입력받기
    graph g1 = input();

    // DFS,BFS함수 호출
    memset(g1.visit, 0, g1.dot_num+1);
	DFS(&g1, g1.start_dot);
	cout << endl;
    
    memset(g1.visit, 0, g1.dot_num+1);
    BFS(&g1, g1.start_dot);
    cout << endl;

    return 0;
}