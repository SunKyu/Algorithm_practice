#include <iostream>
#include <vector>

using namespace std;

int maxPrice = 0;

int main(void)
{
    int N;
    cin >> N;
    vector<int> ti(N+1, 0);
    vector<int> pi(N+1, 0);
    vector<int> dp(N+1, 0);
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> ti[i] >> pi[i];
    }
    int maxP = 0;
    for (int i = 0; i <= N; i++)
    {
        dp[i] = max(dp[i],maxP);
        if(i+ti[i]<=N){
            dp[i+ti[i]] = max(dp[i+ti[i]], dp[i] + pi[i]);
        }
        if(dp[i]>maxP){
            maxP=dp[i];
        }
    }
    cout<<maxP<<endl;
    return 0;
}