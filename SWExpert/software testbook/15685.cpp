//https://www.acmicpc.net/problem/15685

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

//int dx[] = {0, -1, 0, 1};
//int dy[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int info[20][4] = {0, };
int map[101][101] = {0,};
int main(void){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin>>info[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector <int> q;
        int x = info[i][0];
        int y = info[i][1];
        int d = info[i][2];
        int g = info[i][3];
        map[y][x] =1;
        q.push_back(d);
        for (int k = 0; k < g; k++)
        {
            for (int j = q.size() - 1; j >= 0; j--)
            {
                q.push_back((q[j] + 1) % 4);
            }
        }
        for (int j = 0; j < q.size(); j++)
        {
            int nd = q[j];
            int ny = y+dy[nd];
            int nx = x+dx[nd];
            if(nx>=0 && ny>=0 && nx<=100 && ny<= 100){
                map[ny][nx] = 1;
            }
            x = nx;
            y = ny;
        }
    }
    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j<100; j++)
        {
            if(map[i][j] && map[i+1][j+1] && map[i+1][j] && map[i][j+1]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    
}