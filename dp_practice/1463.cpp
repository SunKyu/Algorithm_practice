//https://www.acmicpc.net/problem/1463
#include <iostream>

using namespace std;

int dp[1000001] ={0,};
int N;
int main(void){
    cin>>N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i%3==0) dp[i] = min(dp[i/3]+1, dp[i]);
        if(i%2==0) dp[i] = min(dp[i/2]+1, dp[i]);
    }
    
    cout<<dp[N]<<endl;

    return 0;
}