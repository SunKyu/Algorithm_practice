#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <stdlib.h>
#include <cstring>

using namespace std;

int N, L, R;
int ground[51][51];
bool vi[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int ans = 0;
void print_gr(){
    cout<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<ground[i][j]<<" ";
        }
        cout<<endl;
    }
}

int bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    vi[x][y] = true;
    int cnt = 1;
    int sum = ground[x][y];
    vector<pair<int, int> > v;
    v.push_back(make_pair(x, y));
    while(!q.empty()){
        auto p = q.front();
        x = p.first;
        y = p.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y+ dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<N){
                int pe1 = ground[x][y];
                int pe2 = ground[nx][ny];
                int diff = abs(pe1-pe2);
                if(!vi[nx][ny] && diff>=L && diff<=R){
                    q.push(make_pair(nx, ny));
                    vi[nx][ny] = true;
                    v.push_back(make_pair(nx, ny));
                    cnt++;
                    sum += pe2;
                }
            }
        }
    }
    if(cnt==1){
        return 0;
    }
    int value = sum/cnt;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        ground[x][y] = value;
    }
    return 1;
}
int main(void){
    scanf("%d", &N);
    scanf("%d", &L);
    scanf("%d", &R);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &ground[i][j]);
        }
    }
    int cnt =0;
    int temp = ans;
    
    do{
        temp = ans;
        memset(vi, false, sizeof(vi));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!vi[i][j])
                {
                    ans+= bfs(i, j);
                }
            }
        }
        cnt++;
    }while(temp!=ans);
    printf("%d", cnt-1);
    
}