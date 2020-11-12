#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int now_num = 0;

    while(true){
        if(N<0){
            now_num = -1;
            break;
        }
        else if(N%5 == 0){
            now_num += N/5;
            break;
        }
        else{
            N -= 3;
            now_num +=1;
        }
    }
    cout << now_num << endl;
}