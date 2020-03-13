//https://www.acmicpc.net/problem/2573
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int ice[300][300];
bool visitedbfs[300][300];
bool visited[300][300];
int N, M;
int years, ans = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int> > q;

void dfs(int x, int y){
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx>0&& ny>0 && nx<N && ny<M &&ice[nx][ny]!=0 && !visited[nx][ny])
        {
            dfs(nx, ny);
            //visited[nx][ny] = false;
        }
        
    }
}

void bfs(){
    while (!q.empty())
    {
        int current_size = q.size();
        for (int i = 0; i < current_size; i++)
        {
            auto piece = q.front();
            int x = piece.first;
            int y = piece.second;
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx>=0 &&  ny>=0 && nx<N && ny<M && !visitedbfs[nx][ny]&& ice[nx][ny] == 0 ){
                    if(ice[x][y]>0){
                        ice[x][y] = ice[x][y] - 1;
                        if (ice[x][y] == 0){
                            break;
                        }
                    }
                }
            }
            if(ice[x][y]>0){
                q.push(make_pair(x,y));
            }

            if (q.size() == 0)
            {
                cout<<"0"<<endl;
                return;
            }
        }
        
        years++; 
        int count = 0;
        memset(visitedbfs, false, sizeof(visitedbfs));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (ice[i][j]>0)
                {
                    visitedbfs[i][j] = true;
                }
                if(ice[i][j]!= 0 && !visited[i][j]){
                    count++;
                    dfs(i, j);
                }
            }
        }
        if(count>=2){
            cout<<years<<endl;
            return;
        }
    }
}

int main(void){
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>ice[i][j];
            if(ice[i][j]!=0){
                q.push(make_pair(i, j));
                visitedbfs[i][j] = true;
            }
        }
    }
    bfs();
}