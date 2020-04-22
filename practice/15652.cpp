#include <cstdio>
#include <vector>
using namespace std;
int N;
int M;
bool vi[9];
vector<int> v;

void dfs(int cnt, int idx){
    if(cnt == M){
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    for (int i = idx; i <= N; i++)
    {
        if(!vi[i]){
            v.push_back(i);
            dfs(cnt + 1, i);
            v.pop_back();
        }
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    int cnt = 0;
    
    dfs(0, 1);
    
    return 0;
}