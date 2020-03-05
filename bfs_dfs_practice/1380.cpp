#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int visited[101];
int relationship[101][101] = {0,};
queue<pair<int, int> > q;

int bfs(int i){
    visited[i] = true;
    int depth = 1;
    int res = depth;
    q.push(make_pair(i, depth));
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        int fri = node.first;
        int depth = node.second;
        res = res+depth;
        for(int i = 1; i<=N; i++){
            if(!visited[i] && relationship[fri][i]==1){
                visited[i] = true;
                q.push(make_pair(i, depth+1));
            }
        }
    }
    return res;
}

int main(void){
    cin>>N>>M;
    int a;
    int b;
    int ans;
    for (int i = 0; i < M; i++)
    {
        cin>>a>>b;
        relationship[a][b] = 1;
        relationship[b][a] = 1;
    }
    int init_count=-1;
    int sum_count;
    for (int i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));
        sum_count = bfs(i);
        if(init_count==-1){
            init_count = sum_count;
            ans = i;
        }else{
            if(sum_count<init_count){
                init_count = sum_count;
                ans = i;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}