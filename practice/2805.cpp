#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long N, M;
int main(void){
    scanf("%lld %lld", &N, &M);
    vector<long long> vt(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &vt[i]);
    }
    sort(vt.begin(), vt.end());
    long long left = 0;
    long long right = vt[N-1];
    long long ans =0;
    long long sum = 0;
    long long mid;
    while(left<=right){
        mid = (left+right)/2;
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            if(vt[i]> mid)
                sum += vt[i] - mid;
        }
        if(sum>=M){
            if(ans<mid)
                ans = mid;
            left = mid+1;
        }else{
            right = mid -1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}