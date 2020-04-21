#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int C;

int main(void){
    scanf("%d %d", &N, &C);
    vector<int> vh(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vh[i]);
    }
    sort(vh.begin(), vh.end());
    int left = 1;
    int right = vh[N-1] - vh[0];
    int d = 0;
    int ans;
    while(left<=right){
        int mid = (left+right) /2;
        int start = vh[0];
        int cnt = 1;
        for (int i = 0; i < N; i++)
        {
            d = vh[i] - start;
            if(mid <= d){
                ++cnt;
                start = vh[i];
            }
        }
        if(cnt>=C){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    printf("%d\n", ans);

    return 0;
}