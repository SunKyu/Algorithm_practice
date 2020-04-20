#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<utility>

using namespace std;

int N;
int M;
int box[1000][1000];
int vi[1000][1000];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int unto = 0;
int roto = 0;
int all_to = 0;
int ans = 0;
queue<pair<int, int> > q;

bool check_all_to(){
    if(all_to == roto){
        return true;
    }
    return false;
}

int main(void){
    scanf("%d", &M);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &box[i][j]);
            if(box[i][j] == 0){
                unto++;
            }else if(box[i][j] == 1){
                roto++;
                q.push(make_pair(i, j));
                vi[i][j] = true;
            }
        }
    }
    int q_size;
    int x, y;
    all_to= unto+roto;
    if (all_to == roto){
        printf("0\n");
        return 0;
    }
    int befo = roto;
    while(!q.empty()){
        ans++;
        q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            auto a = q.front();
            q.pop();
            x = a.first;
            y = a.second;
            int nx, ny;
            for (int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];
                if( nx<N && ny<M && nx>=0 && ny>=0){
                    if(vi[nx][ny]){
                        continue;
                    }
                    else if(box[nx][ny] == 0){
                        box[nx][ny] = 1;
                        vi[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                        roto++;
                    }
                }
            }
        }
        if(befo == roto){
            printf("-1\n");
            return 0;
        }
    }
    if(check_all_to()){
        printf("%d\n", ans-1);
    }else{
        printf("-1\n");
    }
    return 0;
}