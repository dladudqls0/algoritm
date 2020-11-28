#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 1001

typedef struct {
    int arr[MAX];
    int N;
}arrr;

void init(arrr * a1){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a1->N;

    for(int i=0; i<a1->N; i++){
        cin >> a1->arr[i];
    }
}

int add(arrr a1){
    int sum=0;
    for(int i=0; i<a1.N; i++){
        for(int j=0; j<=i; j++){
            sum += a1.arr[j];
        }
    }
    return sum;
}

int main(void){
    arrr a1;
    init(&a1);
    sort(a1.arr, a1.arr+a1.N);
    cout<< add(a1) <<endl;
}