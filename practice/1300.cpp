#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N, K; 
int main(void){
    scanf("%d", &N);
    scanf("%d", &K);

    int left = 1;
    int right = K;
    int mid;
    long long cnt;
    int ans;
    while (left<=right)
    {
        cnt = 0;
        mid = (left+right)/2;
        for (int i = 1; i <= N; i++)
        {
            cnt += min(mid/i, N);
        }
        if(cnt>= K){
            right = mid -1;
            ans = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("%d", ans);
    
    

    return 0;
}