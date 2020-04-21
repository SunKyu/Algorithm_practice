#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int K, N;
int main(void){
    scanf("%d %d", &K, &N);
    vector<int> vl(K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &vl[i]);
    }
    sort(vl.begin(), vl.end());
    long long cnt = 0;
    long long left = 1;
    long long right = vl[K-1];
    long long mid;
    long long ans;
    while(left<=right){
        mid = (left+right)/2;
        cnt = 0;
        for (int i = 0; i < K; i++)
        {
            cnt += vl[i]/mid;
        }
        if(cnt>=N){
            left = mid+1;
            ans = mid;
        }else{
            right = mid-1;
        }
    }
    printf("%lld\n", ans);

    return 0;
}