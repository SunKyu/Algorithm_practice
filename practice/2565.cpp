#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
bool comp(vector<int> &a, vector<int> &b){
    return a[0]< b[0];
}

int main(void){
    cin>>n;
    vector<vector<int> > v(n);
    int lis[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = vector<int>(2);
        cin>>v[i][0]>>v[i][1];
    }

    sort(v.begin(), v.end(), comp);
    int len =0;

    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(lis[j] + 1> lis[i] && v[i][1] > v[j][1]){
                lis[i] = lis[j] + 1;
            }
            len = max(len, lis[i]);
        }
    }
    cout<<n-len<<endl;
    
    return 0;
}