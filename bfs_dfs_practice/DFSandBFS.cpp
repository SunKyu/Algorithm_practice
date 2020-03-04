//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;
int M;
int V;
bool visited[1001];
bool visited2[1001];

void dfs(int v, vector<vector<int> > & Graph){
    visited[v] = true;
    for (int i = 1; i <= N; i++)
    {
        if(Graph[v][i] && !visited[i]){
            cout<<i<<" ";
            dfs(i, Graph);
        }
    }
}
void bfs(int v, vector<vector<int> > & Graph){
    cout<<v<<" ";
    queue<int> q;
    q.push(v);
    visited2[v] = true;

    while(q.size()!=0){
        v = q.front();
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if(!visited2[i] && Graph[v][i]){
                visited2[i] = true;
                q.push(i);
                cout<<i<<" ";
            }
        }
    }
}

int main (void){
    cin>>N>>M>>V;
    vector<vector<int> > Graph(N+1, vector<int>(N+1, 0));
    memset(visited, false, sizeof(false));
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin>>a>>b;
        Graph[a][b] = 1;
        Graph[b][a] = 1;
    }
    cout<<V<<" ";
    dfs(V, Graph);
    memset(visited2, false, sizeof(false));
    cout<<endl;
    bfs(V, Graph);
    cout<<endl;
    return 0;
}