//https://www.acmicpc.net/problem/7569
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int M, N, H, ans = 0;
int box[100][100][100] = {0, };
queue <pair<pair<int, int>, int> > Q;
bool visited[100][100][100];
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
bool check_state = true;
bool check_tomato_state(){
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(box[i][j][k] == 0 ) return false;
            }
        }
    }
    return true;
    
}

void bfs(){
    while(!Q.empty()){
        int current_size = Q.size();
        for (int j = 0; j < current_size; j++)
        {
            int x = Q.front().first.first;
            int y = Q.front().first.second;
            int z = Q.front().second;
            Q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if(nx>=0 && ny>=0 && nz>=0 && nx<N && ny<M && nz<H){
                    if(!visited[nx][ny][nz] && box[nx][ny][nz]== 0){
                        visited[nx][ny][nz] = true;
                        Q.push(make_pair(make_pair(nx, ny), nz));
                        box[nx][ny][nz] = 1;
                    }

                }
            }
            if (Q.size() ==0 && check_tomato_state()){
                cout<<ans<<endl;
                return;
            }
            else if(Q.size() == 0 && check_tomato_state() == false){
                cout<<"-1"<<endl;
                return;
            }
        }
        ans++;
    }
}



int main(void){
    cin>>M>>N>>H;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin>>box[j][k][i];
                if(box[j][k][i] == 0) check_state = false;
                if(box[j][k][i] == 1) Q.push(make_pair(make_pair(j,k),i)); 
            }
        }
    }
    if(check_state){
        cout<<"0"<<endl;
        return 0;
    }
    bfs();
}