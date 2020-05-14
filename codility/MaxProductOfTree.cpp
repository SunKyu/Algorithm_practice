// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int size = A.size();
    int a = A[0] * A[1] * A[size-1];
    int b = A[size-1] * A[size-2] * A[size-3];
    if (a==b)
        return a;
    if(a>b){
        return a;
    }
    return b;
}