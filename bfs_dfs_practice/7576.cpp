#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>

using namespace std;

int N;
int M;
int box[1000][1000];
int vi[1000][1000];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int unto = 0;
int roto = 0;
int all_to = 0;
int ans = 0;

bool check_all_to(){
    if(all_to == roto){
        return true;
    }
    return false;
}
void bfs2(int x, int y){

}

void bfs(int x, int y){
    queue<pair<int, int> > q;
    vi[x][y] = true;
    q.push(make_pair(x, y));
    while(!q.empty()){
        auto a = q.front();
        x = a.first;
        y = a.second;
        q.pop();
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx<N&& ny<M && nx>=0 && ny>=0){
                if(box[nx][ny] == 1 && !vi[nx][ny]){
                    vi[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    continue;
                }
                if(box[nx][ny] == 0){
                    box[nx][ny] = 1;
                    vi[nx][ny] = true;
                    roto++;
                }
            }
        }
    }
}

int main(void){
    scanf("%d", &M);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &box[i][j]);
            if(box[i][j] == 0){
                unto++;
            }else if(box[i][j] == 1){
                roto++;
            }
        }
    }
    all_to= unto+roto;
    if (all_to == roto){
        printf("0\n");
        return 0;
    }
    int befo = roto;
    while(!check_all_to()){
        memset(vi, false, sizeof(vi));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(vi[i][j]){
                    continue;
                }
                if(box[i][j] == 1){
                    bfs(i, j);
                }
            }
        }
        if(befo==roto){
            printf("-1\n");
            return 0;
        }
        befo = roto;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}