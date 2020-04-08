#include <iostream>
#include <cstdio>
using namespace std;

int arr[100000];
int dp[100000];
int n;

int main(void){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int max_sum = -1000;

    dp[0] = arr[0];
    max_sum = max(arr[0], max_sum);
    for (int i = 1; i < n; i++)
    {
        dp[i] = arr[i] + dp[i - 1];
        if(dp[i]<0){
            dp[i] = 0;
            max_sum = max(arr[i], max_sum);
        } else{
            max_sum = max(dp[i], max_sum);
        }
    }
    cout<<max_sum<<endl;
    
}