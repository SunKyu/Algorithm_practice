//https://www.acmicpc.net/problem/11727
#include <iostream>
using namespace std;
int dp[1001] = {0,};

int main(void){
    int n;
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    if(n>2){
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}