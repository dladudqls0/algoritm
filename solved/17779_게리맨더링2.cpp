#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 20

typedef struct {
    int peopleNum[MAX][MAX];
    int arr[5];
    int N;
    int d1,d2,x,y;
}map;


void input(map*);
int findSumNum(map*);
int solve(map*);

int main(void){
    map m1;
    input(&m1);
    int value = solve(&m1);
    cout << value <<endl;
    return 0;
}



void input(map * m1){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> m1->N; 
    for(int i=0; i<m1->N; i++){
        for(int j=0; j<m1->N; j++){
            int temp;
            cin >> temp;
            m1->peopleNum[i][j] = temp;
        }
    }
}

int findMinSum(map * m1){
    int x=m1->x;
    int y= m1->y;
    int d1 = m1->d1;
    int d2= m1->d2;
    memset(m1->arr,0,sizeof(m1->arr));

    for (int r = 0; r < m1->N; r++) {
        for (int c = 0; c < m1->N; c++) {
            if (r < x + d1 && c <= y && c < y - (r - x)) {
                m1->arr[0] += m1->peopleNum[r][c];
            }
            else if (r <= x + d2 && c > y && c > y + (r - x)) {
                m1->arr[1] += m1->peopleNum[r][c];
            }
            else if (r >= x + d1 && c < y - d1 + d2 && c < (y - d1 + d2 - (x + d1 + d2 - r))) {
                m1->arr[2] += m1->peopleNum[r][c];
            }
            else if (r > x + d2 && c >= y - d1 + d2 && c > (y - d1 + d2 + (x + d1 + d2 - r))) {
                m1->arr[3] += m1->peopleNum[r][c];
            }
            else {
                m1->arr[4] += m1->peopleNum[r][c];
            }
        }
    }
    sort(m1->arr, m1->arr+5);
    return m1->arr[4]-m1->arr[0];
}

int solve(map * m1){
    int minValue=9999;
    for(int i=1; i<m1->N; i++){
        for(int j=1; j<=m1->N; j++){
            m1->d1=i;
            m1->d2=j;
            int sumD1D2=m1->d1+m1->d2;
            for(int k=0; k<(m1->N)-sumD1D2; k++){    
                for(int l=0; l<(m1->N)-sumD1D2; l++){    
                    m1->x =k+1;
                    m1->y =l+1+m1->d1;
                    int temp=findMinSum(m1);
                    if(minValue> temp)
                        minValue=temp;
                }
            }
        }
    }
    return minValue;
}