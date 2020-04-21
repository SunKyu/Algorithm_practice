#include <cstdio>

using namespace std;
int N;
int main(void){
    scanf("%d", &N);
    long long a;
    long long sum = 0;
    for (int i = 0; i < N*N; i++)
    {
        scanf("%lld", &a);
        sum += a;
    }
    printf("%lld\n", sum);
    
    return 0;
}