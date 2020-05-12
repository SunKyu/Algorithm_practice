// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_count = 0;
    int last_max_count = 0;
    vector<int> ans(N, 0);
    for(auto v: A){
        if(v == N+1){
            last_max_count = max_count;
        }
        else{
            if(ans[v-1]<last_max_count){
                ans[v-1] = last_max_count+1;
            }else{
                ans[v-1]++;
            }
            max_count = max(ans[v-1], max_count);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if(ans[i]<last_max_count)
            ans[i] = last_max_count;
    }
    
    return ans;
}