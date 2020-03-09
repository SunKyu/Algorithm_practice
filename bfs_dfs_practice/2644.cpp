//https://www.acmicpc.net/problem/2644
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
int N;
int M;
int x, y;
int rs[101][101] = {0,};
bool visited[101];
queue<pair<int, int> > q;
int res = 0;

void bfs(int tar, int depth){
    visited[tar] = true;
    q.push(make_pair(tar, depth));
    while (!q.empty())
    {
        auto now = q.front();
        int now_p = now.first;
        int now_depth = now.second;
        q.pop();
        if (now_p == y)
        {
            while(!q.empty())
                q.pop();
            res = now_depth;
            return;
        }
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] || rs[now_p][i]!= 1)
            {
                continue;
            }
            visited[i] = true;
            q.push(make_pair(i, now_depth+1));
        }
    }
}

int main(void){
    memset(visited, false, sizeof(visited));
    cin>>N;
    cin>>x>>y;
    cin>>M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin>>a>>b;
        rs[a][b] = 1;
        rs[b][a] = 1;
    }
    bfs(x, 0);
    if(res==0){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<res<<endl;
    return 0;
}