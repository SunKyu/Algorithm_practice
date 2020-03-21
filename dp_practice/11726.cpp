#include <iostream>

using namespace std;

int dp[1001];

int N;
int main(void){
    cin>>N;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    cout<<dp[N]<<endl;
    

    return 0;
}