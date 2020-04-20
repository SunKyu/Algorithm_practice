#include<cstdio>
#include<cstring>
#include <queue>
#include <utility>

using namespace std;

int T;
int M, N;
int K;
int farm[50][50];
bool vi[50][50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        x = a.first;
        y = a.second;
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = x+ dx[i];
            ny = y+ dy[i];
            if(vi[nx][ny])
                continue;
            if(nx<0||ny<0||nx>=M||ny>=N||farm[nx][ny]!=1)
                continue;
            vi[nx][ny] = true;
            q.push(make_pair(nx,ny));
        }
    }
}



int main(void){
    int x, y;
    scanf("%d", &T);
    int ans = 0;
    while(T--){
        ans = 0;
        memset(vi, false, sizeof(vi));
        memset(farm, 0, sizeof(farm));
        scanf("%d", &M);
        scanf("%d", &N);
        scanf("%d", &K);
        for (int i = 0; i < K; i++)
        {
            scanf("%d", &x);
            scanf("%d", &y);
            farm[x][y] = 1;
        }
        
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(vi[i][j])
                    continue;
                if(farm[i][j] == 1){
                    ans++;
                    bfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}