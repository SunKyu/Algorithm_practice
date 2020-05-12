// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int check = 1;
    for(auto v : A){
        if(v<1){
            continue;
        }
        if (v==check){
            check++;
            continue;
        } 
        else if(v<check){
            continue;
        }
        else{
            return check;
        }
    }
    return check;
}