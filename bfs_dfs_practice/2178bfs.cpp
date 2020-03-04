#include<iostream>
#include<queue>
#include<utility>
#include<cstring>

using namespace std;
int N,M;
int Map[100][100] ={0,};
bool visited[100][100];
int INF = 999999;
int res = INF;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(x, y), 1));
    visited[x][y] = true;
    int count = 1;
    int depth = 1;
    while(1){
        auto loc = q.front();
        q.pop();
        x = loc.first.first;
        y = loc.first.second;
        depth = loc.second;
        count++;
        if(x==N-1 && y == M-1){
            res = min(res, depth);
            break;
        }
        if(depth>res){
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M){
                continue;
            } 
            if(Map[nx][ny] == 0 || visited[nx][ny]){
                continue;
            }
            q.push(make_pair(make_pair(nx, ny), depth+1));
            visited[nx][ny] = true;
        }
    }

}

int main(void){

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
    bfs(0,0);
    cout<<res<<endl;
    return 0;
}