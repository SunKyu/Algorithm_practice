#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int N, M;
int m[8][8] = {0, };
int m2[8][8] = {0, };
bool visited[8][8] = {false, };
bool visited2[8][8] = {false, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
queue<pair<int, int> > vq;
queue<pair<int, int> > vq2;

void bfs(){
    vq2 = vq;
    while(!vq2.empty()){
        auto v = vq2.front();
        vq2.pop();
        int x = v.first;
        int y = v.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || m2[nx][ny] == 2 || m2[nx][ny] == 1)
            {
                continue;
            }
            visited[nx][ny] = true;
            m2[nx][ny] = 2;
            vq2.push(make_pair(nx, ny));
        }
    }
}

void dfs(int cnt){
    if(cnt == 3){
        //spread virus
        //count 0
        memset(visited, false, sizeof(visited));
        memcpy(m2, m, sizeof(m2));
        bfs();
        int cnt_0 = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(m2[i][j] == 0) cnt_0++;
            }
        }
        ans = max(ans, cnt_0);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(m[i][j] == 0){
                m[i][j] = 1;
                dfs(cnt+1);
                m[i][j] = 0;
            }
        }
        
    }
}

int main(void){
    cin>>N>>M;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>m[i][j];
            if(m[i][j]== 2){
                vq.push(make_pair(i, j));
            }
            else if(m[i][j]== 1){
                //visited[i][j] = true;
            }
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}