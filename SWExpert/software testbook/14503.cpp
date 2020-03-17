//https://www.acmicpc.net/problem/14503
#include <iostream>
#include <utility>
#include <cstring>

using namespace std;
int N, M;
int room[51][51] = {0,};
bool visit[51][51];
//robot x, y, direction
pair<pair<int, int>, int> Robot;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int x, y, d;
int ans = 0;

void solution(){
    visit[x][y] = true;
    room[x][y] = 2;
    int nd, nx, ny;
    int cx, cy, cd;
    ans++;
    cx = x;
    cy = y;
    cd = d;
    while(1){
        int check = 0;
        for (int i = 0; i < 4; i++)
        {
            nd = (cd + 3) % 4;
            nx = cx + dx[cd];
            ny = cy + dy[cd];
            if(!visit[nx][ny] && room[nx][ny] == 0&& nx>=0 && ny>=0 && nx<N && ny<M){
                ans++;
                cx = nx;
                cy = ny;
                cd = nd; 
                room[nx][ny] = 2;
                visit[nx][ny] = true;
                break;
            }
            else {
                cd = nd;
                check++;
            }
        }
        if (check == 4){
            nx = cx - dx[(cd+1)%4];
            ny = cy - dy[(cd+1)%4];
            if(nx<0 || ny< 0 || nx>=N || ny>=M || room[nx][ny]==1){
                break;
            }
            cx = nx;
            cy = ny;
        }
    }
    cout<<ans<<endl;
}

int main(void){
    cin>>N>>M;
    cin>>x>>y>>d;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>room[i][j];
        }
    }
    solution();

    return 0;
}