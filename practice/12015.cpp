#include <cstdio>
#include <vector>

using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    vector<int> v;
    vector<int> lis(N, 0);
    int temp;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        if(v.size() == 0){
            v.push_back(temp);
            cnt++;
        }
        else if(temp>v.back()){
            v.push_back(temp);
            cnt++;
        }
        else{
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
            *low = temp;
        }
    }
    printf("%d\n", cnt);
    
    
    
    
    return 0;
}
