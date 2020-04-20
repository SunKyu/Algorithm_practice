#include<iostream>
#include<queue>

using namespace std;
//x+1, x-1, 2*x 3cases
int N;
int K;
bool vi[100001];
int ans = 0;
queue<int> q;
int dx[] = {1, -1, 2};


void bfs(int x){
    int cnt = 0;
    q.push(x);
    vi[x] = true;
    while(!q.empty()){
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            int a = q.front();
            q.pop();
            int nx;
            for (int j = 0; j < 3; j++)
            {
                nx = a + dx[j];
                if(j == 2){
                    nx = a*2;
                }
                if (nx >= 0 && nx <= 100000 && !vi[nx])
                {
                    if(nx == K){
                        ans++;
                        return;
                    }
                    q.push(nx);
                    vi[nx] = true;
                }
            }
        }
        ans++;
    }
}

int main(void){
    cin>>N>>K;
    if(N==K){
        cout<<0<<endl;
        return 0;
    }
    bfs(N);
    cout<<ans<<endl;
    
    return 0;
}