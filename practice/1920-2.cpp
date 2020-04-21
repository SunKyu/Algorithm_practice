#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
bool flag = false;

void solution(int size, int key, vector<int>& v){
    int start = 0;
    int end = size - 1;
    int mid;
    while(end - start >=0){
        mid = (start+end)/2;
        if(v[mid]==key){
            printf("1\n");
            return;
        }
        else if(v[mid]>key){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
    }
    printf("0\n");
    return;
}

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
        solution(N, mmap[i], nmap);
    }
    
    return 0;
}