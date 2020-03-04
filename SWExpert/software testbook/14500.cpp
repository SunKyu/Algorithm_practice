#include<iostream>
#include<vector>
#include<cstring>
#define MAX 500

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int M;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
int ret = 0;

void dfs(int x, int y, int sum, int count){
    Visit[x][y] = true;

    if(count == 3){
        ret = max(sum, ret);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny< 0 || nx>=N || ny>=M) continue;
        if(Visit[nx][ny]) continue;

        dfs(nx, ny, sum+MAP[nx][ny], count+1);
        Visit[nx][ny] = false;
    }
}
void shape1(int x, int y){
    int temp_sum = 0;
    temp_sum = MAP[x][y] + MAP[x+1][y] + MAP[x+2][y] + MAP[x+1][y+1];
    if (temp_sum> ret) ret = temp_sum;
}
void shape2(int x, int y){
    int temp_sum = 0;
    temp_sum = MAP[x][y] + MAP[x+1][y] + MAP[x+2][y] + MAP[x+1][y-1];
    if (temp_sum> ret) ret = temp_sum;
}
void shape3(int x, int y){
    int temp_sum = 0;
    temp_sum = MAP[x][y] + MAP[x][y+1] + MAP[x][y+2] + MAP[x+1][y+1];
    if (temp_sum> ret) ret = temp_sum;
}
void shape4(int x, int y){
    int temp_sum = 0;
    temp_sum = MAP[x][y] + MAP[x][y+1] + MAP[x][y+2] + MAP[x-1][y+1];
    if (temp_sum> ret) ret = temp_sum;
}
int main(void){
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>MAP[i][j];
        }
    }
    for(int i =0; i<N; i++){
        for (int j = 0; j<M; j++){
            memset(Visit, false, sizeof(Visit));
            dfs(i,j, MAP[i][j], 0);
            if(i+2<N && j+1<M) shape1(i, j);
            if(i+2<N && j-1>=0) shape2(i, j);
            if(i+1<N && j+3<M) shape3(i, j);
            if(i-1>=0 && j+3<M) shape4(i, j);
        }
    }
    cout<<ret<<endl;
    return 0;
}
