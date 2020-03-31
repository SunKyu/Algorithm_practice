//https://www.acmicpc.net/problem/11052
#include <iostream>

using namespace std;
int N;
int price[1001];
int dp[1001][1001];
//why start from 1 case work
//why not work from 0
int main(void){
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        cin>>price[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(i == 1){
                dp[i][j]= (j)*price[i];
                continue;
            }
            if (j == i) {
                dp[i][j] = max(dp[i - 1][j], price[i]);
            }
            else if(i> j) {
                dp[i][j] = dp[i - 1][j];
            }
            else if(i<j){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - i] + price[i]);
            }
        }
    }
    
    cout<<dp[N][N]<<endl;
}