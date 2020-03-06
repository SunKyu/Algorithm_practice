//https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
#define MAX 25

using namespace std;

int Map[MAX][MAX];
bool visited[MAX][MAX];
int N;
vector<int> res;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x,y)); 
    visited[x][y] = true;
    int num = 1;
    while(!q.empty()){
        auto head = q.front();
        x = head.first;
        y = head.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            {
                continue;
            }
            if (visited[nx][ny] || Map[nx][ny] == 0)
            {
                continue;
            }
            num++;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    res.push_back(num);
}

int main(void){
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char a;
            cin>>a;
            if(a=='0')
                Map[i][j] = 0;
            if(a=='1')
                Map[i][j] = 1;
        }
    }
    memset(visited, false, sizeof(false));
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0;  j < N;  j++)
        {
            if(!visited[i][j] && Map[i][j] !=0){
                bfs(i, j);
                count++;
            }
        }
    }
    cout<<count<<endl;
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}
