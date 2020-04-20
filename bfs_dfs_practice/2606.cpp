#include <cstdio>

int n;
int conn_cnt;
int net[101][101] = {-1, };
bool vi[101];
int ans = 0;

void dfs(int s){
    vi[s] = true;
    ans++;
    for (int i = 1; i <= n; i++)
    {
        if (vi[i])
        {
            continue;
        }
        if (net[s][i] == 1)
        {
            dfs(i);
        }
    }
}

int main(void){
    scanf("%d", &n);
    scanf("%d", &conn_cnt);
    int a, b;
    for (int i = 0; i < conn_cnt; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        net[a][b] = 1;
        net[b][a] = 1;
    }
    dfs(1);
    printf("%d", ans-1);
    return 0;
}