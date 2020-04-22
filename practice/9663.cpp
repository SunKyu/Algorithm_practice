#include<cstdio>
#include<stdlib.h>
using namespace std;


int N;
int col[15];
int cnt = 0;
int ans = 0;

bool is_valid(int idx){
    for (int i = 0; i < idx; i++)
    {
        if(col[i]==col[idx] || abs(col[idx]-col[i])==(idx-i)){
            return false;
        }
    }
    return true;
}

void dfs(int cnt){
    if(cnt == N){
        ans++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        col[cnt] = i;
        if(is_valid(cnt)){
            dfs(cnt+1);
        }
    }
}


int main(void){
    scanf("%d", &N);

    dfs(0);
    printf("%d", ans);

    return 0;
}