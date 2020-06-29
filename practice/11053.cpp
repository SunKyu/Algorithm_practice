#include <iostream>

using namespace std;


int a[1000] = {0,};
int dp[1000] = {1, };

int main(void){
    int K;
    cin>>K;
    for (int i = 0; i < K; i++)
    {
        cin>>a[i];
    }
    dp[0] = 1;
    for (int i = 0; i < K; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(a[i]>a[j] && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        if(dp[i] > ans){
            ans = dp[i];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}