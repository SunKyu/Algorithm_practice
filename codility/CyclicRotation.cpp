vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int size = A.size();
    if (size == 0){
        return A;
    }
    if (K%size == 0){
        return A;
    }
    int mk = K%size;
    vector<int> ans(A.size(),0 );
    for (int i = 0; i < A.size(); i++)
    {
        int mi = i+mk;
        if(mi>=A.size()){
            mi = mi%(A.size());
        }
        ans[mi] = A[i];
    }
    
    return ans;

}