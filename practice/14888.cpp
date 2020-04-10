#include <iostream>
using namespace std;

int n;
int nums[100];
int ops[4] = {
    0,
};
int min_value = 1000000000;
int max_value = -1000000000;

void dfs(int idx, int res)
{
    if (idx == n)
    {
        for (int i = 0; i < 4; i++)
        {
            if(ops[i]>0){
                return;
            }
        }
        max_value = max(max_value, res);
        min_value = min(min_value, res);
        return;
    }
    for (int j = 0; j < 4; j++)
    {
        if (ops[j] > 0)
        {
            ops[j]--;
            if (j == 0)
            {
                dfs(idx + 1, res + nums[idx]);
            }
            else if (j == 1)
            {
                dfs(idx + 1, res- nums[idx]);
            }
            else if (j == 2)
            {
                dfs(idx + 1, res*nums[idx]);
            }
            else if (j == 3)
            {
                dfs(idx + 1, res/nums[idx]);
            }
            ops[j]++;
        }
    }
}

int main(void){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin>>ops[i];
    }
    min_value = 1000000000;
    dfs(1, nums[0]);
    cout<<max_value<<endl;
    cout<<min_value<<endl;

    return 0;
}