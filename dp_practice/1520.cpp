//https://www.acmicpc.net/problem/1520

#include<iostream>

using namespace std;
int n, m;
int mo[501][501];
int dp[501][501] = {0, };
bool visited[501][501] = {false,};
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int dfs(int x, int y){
    if(x==m-1&&y==n-1){
        return 1;
    }
    if(visited[x][y]){
        return dp[x][y];
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<m&&ny<n&&nx>=0&&ny>=0){
            if(mo[x][y]>mo[nx][ny]){
                dp[x][y] += dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}
int main(void){
    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>mo[i][j];
        }
    }
    
    cout<<dfs(0,0)<<endl;
    return 0;
}
