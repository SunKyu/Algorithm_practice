// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int len = Y - X;
    if (len == 0){
        return 0;
    }
    if(len/D == 0){
        return 1;
    }
    if(len%D == 0){
        return len/D;
    }
    return len/D + 1;
    
}