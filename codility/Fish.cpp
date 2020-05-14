#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    vector<int> down;
    int eat_count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(B[i] == 1){
            down.push_back(A[i]);
            continue;
        }
        if(down.empty())
            continue;
        int b = down.back();
        if(b>A[i]){
            eat_count++;
        }
        else{
            eat_count++;
            down.pop_back();
        }
    }
    return A.size()-eat_count;
}