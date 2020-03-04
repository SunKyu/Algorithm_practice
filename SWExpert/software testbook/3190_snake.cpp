#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int N;
int K;
int L;
vector<vector<int> > Board(101, vector<int>(101, 0));
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
const int APPLE = 1;
const int SNAKE = -1;
pair<int, char> dir_change[101];




int main(void){
    cin>>N>>K;
    int x;
    int y;
    for (int i = 0; i < K; i++)
    {
        cin>>x>>y;
        Board[x-1][y-1] = APPLE;
    };
    cin>>L;
    int a;
    int b;
    for (int i = 0; i < L; i++)
    {
        cin>>dir_change[i].first>>dir_change[i].second;
    }
    Board[0][0] = SNAKE;
    pair<int, int> Head(make_pair(0,0));
    queue<pair<int, int> >  snakeq;
    snakeq.push(Head);
    int cur_change_index=0;
    int cur_di = 0;
    int sec = 0;
    while(1){
        sec++;
        int nx = Head.first + dx[cur_di];
        int ny = Head.second + dy[cur_di];
        if(nx<0 || ny <0 || nx>=N || ny>= N)
        {
            break;
        } else if(Board[nx][ny] == SNAKE){
            break;
        } else if(Board[nx][ny] != APPLE){
            pair<int, int> tail = snakeq.front();
            snakeq.pop();
            Board[tail.first][tail.second] = 0;
        }
        Head = make_pair(nx, ny);
        snakeq.push(Head);
        Board[nx][ny] = SNAKE;
        int dir_change_sec = dir_change[cur_change_index].first;
        if( cur_change_index< L && dir_change_sec == sec){
            char dir = dir_change[cur_change_index].second;
            if(dir == 'L'){
                cur_di = (cur_di + 3) %4;
            }
            else if(dir == 'D'){
                cur_di = (cur_di + 1) %4;
            }
            cur_change_index++;
        }
    }
    cout<<sec<<endl;


    return 0;
}