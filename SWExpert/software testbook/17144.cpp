//https://www.acmicpc.net/problem/17144
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;
int R, C;
int T;
int room[50][50];
int room2[50][50] = {0, };
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ccw[] = {0, 3, 1, 2};
int cw[] = {0, 2, 1, 3};

int A[2] = {0};
int main(void){
    cin>>R>>C>>T;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin>>room[i][j];
            if (room[i][j] == -1)
            {
                A[cnt] = i;
                cnt++;
            } 
        }
    }
    for (int k = 0; k < T; k++)
    {
        memset(room2, 0, sizeof(room2));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if(room[i][j] == -1) continue;
                if(room[i][j]>0){
                    int cnt = 0;
                    for (int l = 0; l < 4; l++)
                    {
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        if(nx>=0 && ny>=0 && nx<R && ny<C  ){
                            if((nx == A[0] || nx==A[1]) && ny == 0){
                                continue;
                            }
                            room2[nx][ny] += room[i][j]/5;
                            cnt++;
                        }
                    }
                    room2[i][j] += room[i][j] - ((room[i][j]/5)*cnt);
                }
            }
        }
        memcpy(room, room2, sizeof(room2));
        int x = A[0];
        int y = 1;
        for (int i = 0; i < 4; i++)
        {
            while (1)
            {
                int nx = x + dx[ccw[i]];
                int ny = y + dy[ccw[i]];
                if(nx == A[0] && ny == 0 ){
                    break;
                }
                if(ny>=C || nx<0 || ny<0){
                    break;
                }
                room[nx][ny] = room2[x][y];
                x = nx;
                y = ny;
            }
        }
        room[A[0]][1] = 0;
        x = A[1];
        y = 1;
        for (int i = 0; i < 4; i++)
        {
            while (1)
            {
                int nx = x + dx[cw[i]];
                int ny = y + dy[cw[i]];
                if(nx == A[1] && ny == 0 ){
                    break;
                }
                if(ny>=C || nx>=R || ny<0){
                    break;
                }
                room[nx][ny] = room2[x][y];
                x = nx;
                y = ny;
            }
        }
        room[A[1]][1] = 0;
    }
    ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans+= room[i][j];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}