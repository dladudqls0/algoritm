#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    int answer=1;

    switch(N){
        case 1:
            break;
        case 2:
            answer+=(M-1)/2;
            if(answer>4) answer=4;
            break;
        default:
            if(M<7){
                answer+=(M-1);
                if(answer>4) answer=4;
            }
            else
                answer+=(4+(M-7));
            
            break;
    }

    

    cout << answer <<endl;

    return 0;
}