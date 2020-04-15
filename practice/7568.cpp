#include <iostream>

using namespace std;
int p[50][3] = {1, };

int main(){
    int n;
    cin>>n;
    int w, h;
    for (int i = 0; i < n; i++)
    {
        cin>>w>>h;
        p[i][0] = w;
        p[i][1] = h;
        p[i][2] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j){
                continue;
            }
            if(p[i][0]<p[j][0] && p[i][1]<p[j][1]){
                p[i][2] = p[i][2] +  1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<p[i][2]<<" ";
    }
    return 0;
}