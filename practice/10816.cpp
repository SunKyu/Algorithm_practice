#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int M;

int main(void){
    scanf("%d", &N); 
    vector<int> nv(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nv[i]); 
    }
    
    scanf("%d", &M); 
    vector<int> mv(M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &mv[i]); 
    }

    sort(nv.begin(), nv.end());
    for (int i = 0; i < M; i++)
    {
        auto a = equal_range(nv.begin(), nv.end(), mv[i]);
        printf("%ld ", (a.second-a.first));
    }
    

    return 0;
}