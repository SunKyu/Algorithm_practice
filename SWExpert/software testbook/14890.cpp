//https://www.acmicpc.net/problem/14890
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N;
    int L;
    cin>>N>>L;
    vector<vector<int> > M(N*2, vector<int>(N,0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>M[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            M[i+N][j] = M[j][i];
        }
    }
    int ret = 0;
    int cnt = 0;
    for (int i = 0; i < N*2; i++)
    {
        cnt = 1;
        for (int j = 0; j< N; j++){
            if (j == N-1 && cnt>=0) 
            {
                ret++; 
            }
            else if(M[i][j] == M[i][j+1]) {
                cnt++;
            }
            else if(M[i][j] + 1 == M[i][j+1] && cnt>=L) 
            {
                cnt = 1;
            }
            else if(M[i][j] - 1 == M[i][j+1] && cnt>=0) {
                cnt = 1 - L;
            }
            else break;
        }
    }
    cout<<ret<<endl;
    
    return 0;
}