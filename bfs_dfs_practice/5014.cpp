//https://www.acmicpc.net/problem/5014

#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int F, S, G, U, D;
int ans = -1;
bool visited[10000001];
queue<pair<int, int> > q;

void bfs(){
    while (!q.empty())
    {
        auto current = q.front();
        int current_floor = current.first;
        int count = current.second;
        q.pop();
        if(ans!= -1 && count>ans){
            continue;
        }
        if(current_floor == G){
            if(ans==-1){
                ans = count;
            }
            else{
                ans = min(count, ans);
            }
        }
        int going_up = current_floor +U;
        int going_down = current_floor -D;
        if(going_up <= F && !visited[going_up]){
            q.push(make_pair(going_up, count+1));
            visited[going_up] = true;
        }
        if(going_down > 0 && !visited[going_down]){
            q.push(make_pair(going_down, count+1));
            visited[going_down] = true;
        }
    }
}

int main(void){
    cin>>F>>S>>G>>U>>D;
    q.push(make_pair(S, 0));
    visited[S] = 0;
    bfs();
    if(ans == -1){
        cout<<"use the stairs"<<endl;
        return 0;
    }
    cout<<ans<<endl;
    
    return 0;
}
