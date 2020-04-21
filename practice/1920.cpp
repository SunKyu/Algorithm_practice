#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
bool flag = false;

int main(void){
    scanf("%d", &N);
    vector<int> nmap(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nmap[i]);
    }
    
    scanf("%d", &M);
    vector<int> mmap(M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &mmap[i]);
    }
    sort(nmap.begin(), nmap.end());
    for (int i = 0; i < M; i++)
    {
        if(binary_search(nmap.begin(), nmap.end(), mmap[i])){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    
    return 0;
}