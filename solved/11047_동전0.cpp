#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 11

typedef struct{
    int arr[MAX];
    int N;
    int K;
}arr;

void init(arr * a1){
    ios::sync_with_stdio(false);
    cin.tie();
    
    cin >> a1->N >> a1->K;
    for(int i=0; i<a1->N; i++){
        cin >> a1->arr[i];
    }
}

int solve(arr a1){
    int nowmoney=a1.K;
    int temp=0;
    int count = 0;
    for(int i=0; i<a1.N; i++){
        count += nowmoney/a1.arr[i];
        nowmoney %= a1.arr[i];
    }
    return count;
}

bool compare(int i, int j){
    return j < i;
}

int main(void){
    arr a1;
    init(&a1);
    sort(a1.arr,a1.arr+a1.N,compare);
    cout<< solve(a1) << endl;
}

