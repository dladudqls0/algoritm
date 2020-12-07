#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define MAX 51

typedef struct {
    int visit[MAX][MAX];
    int N,M;
    int r,c,d;
    int count;
}map;


void init(map * m1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m1->N >> m1->M;
    cin >> m1->r >> m1->c >> m1->d;

    for(int n=0; n<m1->N; n++){
        for(int m=0; m<m1->M; m++){
            cin >> m1->visit[n][m];
        }
    }
}
int main(void){
    int direct[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
    map m1;
    init(&m1);
    m1.count=0;
    int c=0;

    while(1){
        if(!m1.visit[m1.r][m1.c]){
            m1.count++;
            m1.visit[m1.r][m1.c]=2;
        }
        
        //왼쪽방향 조회
        int nextr, nextc;
        int temp= (m1.d+3)%4;
        nextr = m1.r+direct[temp][0];
        nextc = m1.c+direct[temp][1];


        if(m1.visit[nextr][nextc]){
            //2-b

            if(c==4){
                c=0;
                int temp2 = (m1.d+2)%4;
                nextr = m1.r+direct[temp2][0];
                nextc = m1.c+direct[temp2][1];
                
                if(m1.visit[nextr][nextc]==1){
                    //2-d
                    break;
                }
                else{
                    //2-c
                    m1.r = nextr;
                    m1.c = nextc;
                    continue;
                }
            }

            m1.d+=3;
            c++;
            
            continue;
        }
        else{
            //2-a
            m1.d+=3;
            m1.r = nextr;
            m1.c = nextc;
            c=0;
            continue;
        }
        cout<< m1.r << " " << m1.c << endl;
    }
    cout<< m1.count << endl;
    return 0;
}