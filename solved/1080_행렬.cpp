#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 52
using namespace std;

typedef struct{
    int N,M;
    int check[MAX][MAX];
}Array;

void init(Array * a1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a1->N >> a1->M;
    char A[MAX][MAX];
    char B[MAX][MAX];

    for(int i=0; i<a1->N; i++){
        cin >> A[i];
    }
    for(int i=0; i<a1->N; i++){
        cin >> B[i];
    }

    for(int i=0; i<a1->N; i++){
        for(int j=0; j<a1->M; j++){
            if(A[i][j]==B[i][j]){
                a1->check[i][j]=1;
            }
            else{
                a1->check[i][j]=-1;
            }
        }
    }

}

void flip(Array * a1,int N,int M){
    for(int n=N; n<3+N; n++){
        for(int m=M; m<3+M; m++){
            a1->check[n][m] *= -1;
        }
    }
}

int check(Array a1){
    for(int n=0; n<a1.N; n++){
        for(int m=0; m<a1.M; m++){
            if(a1.check[n][m]==-1)
                return 0;
        }
    }
    return 1;
}

int main(void){
    Array a1;
    init(&a1);
    
    int count=0;
    for(int n=0; n<a1.N-2; n++){
        for(int m=0; m<a1.M-2; m++){
            if(a1.check[n][m]==-1){
                flip(&a1,n,m);
                count++;
            }
        }
    }

    if(check(a1)) cout<<count<<endl;
    else cout<<-1<<endl;
}
