#include<iostream>
#include<cstdio>

using namespace std;
char b[50][50];

int main(void){
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);
    int size = 8;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", b[i]);
    }
    int res = 50*50;
    for (int i = 0; i <= n-size; i++)
    {
        for (int j = 0; j <= m-size; j++)
        {
            int cntW = 0;
            int cntB = 0;
            for (int k = i; k < i+size; k++)
            {
                for (int o = j; o < j+size; o++)
                {
                    if((k%2) ^ (o%2)){
                        if(b[k][o] == 'W') cntW++;
                    }
                    else{
                        if(b[k][o] == 'B') cntW++;
                    }
                }
            }
            cntB = 64 - cntW;
            res = min(res, cntW);
            res = min(res, cntB);
        }
    }
    cout<<res<<endl;
    
    return 0;
}