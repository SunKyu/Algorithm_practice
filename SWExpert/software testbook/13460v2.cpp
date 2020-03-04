//https://www.acmicpc.net/problem/13460
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int N, M;
int Rx, Ry;
int Bx, By;
int HoleX, HoleY;
int INF = 9999999;
int res = INF;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visited[10][10][10][10];

void tilt(int &x1, int &y1, int &x2, int &y2, int dir, vector<vector<char> > &Map)
{
    while (Map[x1 + dx[dir]][y1 + dy[dir]] != '#')
    {
        x1 = x1 + dx[dir];
        y1 = y1 + dy[dir];
        if (Map[x1][y1] == 'O')
        {
            break;
        }
    }
    while (Map[x2 + dx[dir]][y2 + dy[dir]] != '#')
    {
        x2 = x2 + dx[dir];
        y2 = y2 + dy[dir];
        if (Map[x2][y2] == 'O')
        {
            break;
        }
    }
}
bool is_hole(int x1, int y1)
{
    if (x1 == HoleX && y1 == HoleY)
        return true;
    return false;
}

void dfs(int rx, int ry, int bx, int by, vector<vector<char> > &Map, int cnt)
{
    if (cnt > 10)
    {
        return;
    }
    if (cnt >= res)
    {
        return;
    }
    //R B hole same time
    if(is_hole(rx, ry)&& is_hole(bx,by)) return;
    //!R only B return
    if(!is_hole(rx, ry)&& is_hole(bx,by)) return;
    //onlyR res = min(cnt, res);
    if(is_hole(rx, ry)&& !is_hole(bx, by)){
        res = min(res, cnt);
    }

    for (int i = 0; i < 4; i++)
    {
        int nx1 = rx;
        int ny1 = ry;
        int nx2 = bx;
        int ny2 = by;
        //tilt
        tilt(nx1, ny1, nx2, ny2, i, Map);
        if (nx1 == nx2 && ny1 == ny2)
        {
            if (is_hole(nx1, ny1))
                continue;
            switch (i)
            {
                case 0:
                    ry - by > 0? ny2--: ny1--;
                    break;
                case 1:
                    ry - by <0? ny2++: ny1++;
                    break;
                case 2:
                    rx - bx > 0? nx1--: nx2--;
                    break;
                case 3:
                    rx-by > 0 ? nx1++: nx2++;
                    break;
                default:
                    break;
            }
        }
        if(!visited[nx1][ny1][nx2][ny2]){
            visited[nx1][ny1][nx2][ny2] = true;
            dfs(nx1, ny1, nx2, ny2, Map, cnt+1);
            visited[nx1][ny1][nx2][ny2] = false;
        }
    }
}

int main(void)
{
    cin >> N >> M;
    vector<vector<char> > Map(N, vector<char>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'R')
            {
                Rx = i;
                Ry = j;
            }
            if (Map[i][j] == 'B')
            {
                Bx = i;
                By = j;
            }
            if (Map[i][j] == 'O')
            {
                HoleX = i;
                HoleY = j;
            }
        }
    }
    //input
    memset(visited, false, sizeof(false));
    visited[Rx][Ry][Bx][By] = true;
    dfs(Rx, Ry, Bx, By, Map, 0);
    if (res==INF){
        cout<<"-1"<<endl;
    }
    else{
        cout<<res<<endl;
    }

    return 0;
}