//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <cstring>

using namespace std;
int N,M;
int Map[100][100] ={0,};
bool visited[100][100];
int INF = 999999;
int res = INF;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int count){
    visited[x][y] =true;
    if(count>res){
        return;
    }
    if (x == N-1 && y==M-1){
        if (count<res){
            res = count;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||ny<0||nx>=N || ny>=M){
            continue;
        }
        if(visited[nx][ny] || Map[nx][ny] == 0){
            continue;
        }
        dfs(nx, ny, count+1);
        visited[nx][ny] = false;
    }
}


int main (void){
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char a ;
            cin>>a;
            if(a=='1'){
                Map[i][j] = 1;
            }else{
                Map[i][j] = 0;
            }
        }
    }
    memset(visited, false, sizeof(false));
    dfs(0,0,0);
    res = res+1;
    cout<<res<<endl;

    return 0;
}