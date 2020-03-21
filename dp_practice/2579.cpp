#include <iostream>

using namespace std;

int N;
int stairs[300];
int dp[300];

int main(void){
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>stairs[i];
    }
    dp[0] = stairs[0];
    dp[1] = dp[0] + stairs[1];
    dp[2] = max(stairs[2] + dp[0], stairs[1]+stairs[2]);
    for (int i = 3; i < N; i++)
    {
        dp[i] = max(stairs[i]+ dp[i-2], dp[i-3]+ stairs[i-1]+stairs[i]);
    }
    
    cout<<dp[N-1]<<endl;
    return 0;
}