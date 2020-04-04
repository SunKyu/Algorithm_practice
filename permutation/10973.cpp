#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int main(void){
    cin>>N;
    vector<int> nums(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin>>nums[i];
    }

    int flag=false;
    do
    {
        if(flag){
            for (int i = 0; i < N; i++)
            {
                cout<<nums[i]<<" ";
            }
            return 0;
            break;
        }
        flag = true;
    } while (prev_permutation(nums.begin(), nums.end()));
    cout<<"-1"<<endl;
    return 0;
}