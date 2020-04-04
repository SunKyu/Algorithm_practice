#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int nums[10];
bool visited[10];
void dfs(int cnt, string ans){
    if(cnt==N){
        cout<<ans<<'\n';
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        dfs(cnt+1, ans+to_string(nums[i])+' ');
        visited[i] = false;
    }
    

}
int main(void){
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        nums[i] = i+1;
    }
    dfs(0, "");
    return 0;
}