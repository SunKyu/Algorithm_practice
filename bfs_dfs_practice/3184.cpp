#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
int R, C;
char yard[251][251];
bool visited[251][251] = {false, };
int s_wolf = 0;
int s_lamp = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int> > q;

void bfs(int x, int y){
    q.push(make_pair(x, y));
    visited[x][y] = true;
    int cnt_wolf = 0;
    int cnt_lamp = 0;
    bool flag = false;
    while(!q.empty()){
        auto point = q.front();
        x = point.first;
        y = point.second;
        q.pop();
        if(yard[x][y]=='v'){
            cnt_wolf++;
        }
        if(yard[x][y]=='o'){
            cnt_lamp++;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=R || ny>= C){
                continue;
            }
            if(visited[nx][ny]){
                continue;
            }
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }
    if(cnt_lamp>cnt_wolf){
        s_lamp+= cnt_lamp;
    }
    else{
        s_wolf += cnt_wolf;
    }
}

int main(void){
    cin>>R>>C;
    char a;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin>>a;
            if(a=='#') visited[i][j] = true;
            yard[i][j] = a;
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if(visited[i][j]) continue;
            bfs(i, j);
        }
    }
    cout<<s_lamp<<" "<<s_wolf<<endl;
    return 0;
}