//https://www.acmicpc.net/problem/17822
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int N, M, T;
int rot[50][50] = {0, };
bool visited[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool flag = false;


void dfs(int x, int y, int value, int depth){
    visited[x][y] = true;
    if (depth>1){
        flag = true;
    }
    if(rot[x][y] == 0){
        return;
    }
    /*
    if(rot[x][y] == value && depth != 1){
        cout<<x<<" "<<y<<endl;
        rot[x][y] = 0;
    }
    */
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (ny== M)
        {
            ny = 0;
        }
        if (ny == -1){
            ny = M-1;
        }
        if(nx<0 || ny<0 || nx>=N || ny>=M || visited[nx][ny] || rot[nx][ny]!=value || rot[nx][ny] == 0){
            continue;
        }
        dfs(nx, ny, value, depth+1);
        rot[x][y] = 0;
        rot[nx][ny] = 0;
        visited[nx][ny] = false;
    }
}

void rotate(int x, int d, int k){
    for (int i = 0; i < N; i++)
    {
        if((i+1) % x == 0){
            int v = k;
            if(d==1){
                v = M - k;
            }
            int a[M];
            memset(a, 0, sizeof(a));
            for (int j = 0; j < M; j++)
            {
                int des = (j+v) % M;
                a[des] = rot[i][j];
            }
            for (int j = 0; j < M; j++)
            {
                rot[i][j] = a[j];
            }
        }
    }
}

int main(void){
    memset(visited, false, sizeof(visited));
    cin>>N>>M>>T;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>rot[i][j];
        }
    }
    for (int i = 0; i < T; i++)
    {
        int x, d, k;
        cin>>x>>d>>k;
        rotate(x, d, k);
        memset(visited, false, sizeof(visited));
        flag = false;
        for (int q = 0; q < N; q++)
        {
            for (int j = 0; j < M; j++)
            {
                dfs(q, j, rot[q][j], 1);
            }
        }
        if(!flag){
            int sum = 0;
            int count = 0;
            for (int q = 0; q < N; q++)
            {
                for (int j = 0; j < M; j++)
                {
                    if(rot[q][j]>0){
                        count = count + 1;
                        sum = sum + rot[q][j];
                    }
                }
            }
            float avg = float(sum) / float(count);
            for (int q = 0; q < N; q++)
            {
                for (int j = 0; j < M; j++)
                {
                    if(rot[q][j]>avg){
                        rot[q][j] -= 1;
                    }
                    else if (rot[q][j]<avg && rot[q][j] != 0){
                        rot[q][j] += 1;
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            res = res + rot[i][j];
        }
        cout<<endl;
    }
    cout<<res<<endl;
    return 0;
}
//first rotate
//dfs or bfs left right up down injunction condition only same
//get sum of rotation