// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int P = 1;
    int sum = 0;
    for(auto a: A){
        sum+= a;
    }
    int sum1=A[0];
    int sum2 = sum - sum1;
    int min_v = 100000000;
    for(P=1; P<A.size(); P++){
        min_v = min(min_v, abs(sum1-sum2));
        sum1 += A[P];
        sum2 = sum -sum1;
    }
    return min_v;
    
}