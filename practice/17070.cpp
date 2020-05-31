#include <cstdio>
using namespace std;
int N;
int h[17][17];
int vi[17][17];

int dx[3] ={0, 1, 1};
int dy[3] ={1, 0, 1};

int ans = 0;

void dfs(int x, int y, int di){
    if(x == N && y ==N){
        ans++;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if((di==0 && i== 1) || (di==1 && i==0)){
            continue;
        }
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<=N && ny<=N && h[nx][ny]!=1){
            if(i==2){
                if(h[x+1][y]==1 || h[x][y+1]==1){
                    continue;
                }
                vi[x+1][y] = 1;
                vi[x][y+1] = 1;
                vi[nx][ny] = 1;
                dfs(nx, ny, i);
                vi[x+1][y] = 0;
                vi[x][y+1] = 0;
                vi[nx][ny] = 0;
            }
            else{
                vi[nx][ny] = 1;
                dfs(nx, ny, i);
                vi[nx][ny] = 0;
            }
        }
    }
}
int main(void){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &h[i][j]);
        }
    }

    vi[1][1] = 1;
    vi[1][2] = 1;
    dfs(1,2, 0);
    printf("%d\n", ans);

    return 0;
}