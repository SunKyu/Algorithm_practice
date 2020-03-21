//https://www.acmicpc.net/problem/10844

#include <iostream>

using namespace std;

int N;
long long dp[101][11] = {0, };
int main(void){
    cin>>N;
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i-1][1];
        for (int j = 1; j <= 9; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += dp[N][i];
    }
    cout<<(ans%1000000000)<<endl;
    return 0;
}