#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
int N;
int Map[100][100] = {0,};
bool visited[100][100];
int max_level = 0;
int max_area = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y, int k){
    visited[x][y] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if(visited[nx][ny]|| nx<0|| ny<0 || nx>=N || ny>=N || (Map[nx][ny]-k) <= 0){
                continue;
            }
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
        
    }
    
    
}

int main(void){
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int a;
        for (int j = 0; j < N; j++)
        {
            cin>>a;
            max_level = max(a, max_level);
            Map[i][j] = a;
        }
    }
    for (int k = 0; k <= max_level; k++)
    {
        int count = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] || (Map[i][j] - k) <= 0)
                {
                    continue;
                }
                count = count + 1;
                bfs(i, j, k);
            }
        }
        max_area = max(count, max_area);
    }
    cout<<max_area<<endl;
    
    return 0;
}