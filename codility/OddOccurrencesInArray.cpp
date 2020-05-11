// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int temp = A[0];
    int count = 0;
    for(int i = 0; i<A.size(); i++){
        if(temp == A[i]){
            count++;
        }
        else{
            if(count %2 == 1){
                return temp;
            }
            temp = A[i];
            count=1;
        }
    }
    if(count%2 == 1){
        return temp;
    }
}