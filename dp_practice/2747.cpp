//https://www.acmicpc.net/problem/2747

#include <iostream>
using namespace std;

int fn[46] = {0, };

int main(void){
    int n;
    cin>>n;
    fn[0] = 0;
    fn[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fn[i] = fn[i-1] + fn[i-2];
    }
    cout<<fn[n]<<endl;
    return 0;
}