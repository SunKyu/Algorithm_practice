//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>

using namespace std;
int N;
bool is_start[21];
int players[21][21];
int ans = 9999999;

void dfs(int player, int cnt){
    if(N/2==cnt){
        vector<int> start;
        vector<int> link;

        for (int i = 0; i < N; i++)
        {
            if(is_start[i]){
                start.push_back(i);
            } else{
                link.push_back(i);
            }
        }
        int start_res=0;
        int link_res = 0;
        for (int i = 0; i < start.size(); i++)
        {
            for (int j = i+1; j < start.size(); j++)
            {
                start_res += players[start[i]][start[j]];
                start_res += players[start[j]][start[i]];
                link_res += players[link[j]][link[i]];
                link_res += players[link[i]][link[j]];
            }
        }
        ans = min(ans, abs(start_res-link_res));
        return;
    }
    else{
        for (int i = player+1; i < N; i++)
        {
            if(!is_start[i]){
                is_start[i]= true;
                dfs(i, cnt+1);
                is_start[i] = false;
            }
        }
    }
    
}



int main(void){
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>players[i][j];
        }
    }
    dfs(0,0);
    cout<<ans<<endl;;

    return 0;
}