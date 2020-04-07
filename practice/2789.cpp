#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
int cards[100] ={0,};
int max_value = 0;
bool visited[100] = {false,};

void bfs(int idx, int sum_value ,int cnt){
    if(sum_value>M){
        return;
    }
    if(cnt ==3){
        max_value = max(max_value, sum_value);
        return;
    }
    for (int i = idx; i < N; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        bfs(idx+1, sum_value + cards[i], cnt+1);
        visited[i] = false;
    }
}

int main(void){
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&cards[i]);
    }

    bfs(0, 0, 0);
    printf("%d\n", max_value);
    return 0;
}