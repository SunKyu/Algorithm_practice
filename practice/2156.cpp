#include <iostream>
#include <cstdio>

using namespace std;
int n;
int wine[10003] = {0, };
int dp[10003] = {0, };

int main(void){
    scanf("%d", &n);
    int ans = 0;
    for (int i = 3; i < n+3; i++)
    {
        scanf("%d", &wine[i]);
    }
    for (int i = 3; i < n+3; i++)
    {
        dp[i] = max(dp[i - 2] + wine[i], dp[i - 3] + wine[i] + wine[i - 1]);
        dp[i] = max(dp[i - 1], dp[i]);
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    
    return 0;
}