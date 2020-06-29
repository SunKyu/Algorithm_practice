#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
int vi[4] = {false, };

bool check_rotate(vector<string> & gear, int target, int target2){
    if(target2 <0 || target2 >3){
        return false;
    }
    if(target2<target){
        if (gear[target2][2] != gear[target][6]){
            return true;
        }
    }
    else{
        if (gear[target][2] != gear[target2][6]){
            return true;
        }
    }
    return false;
}

void rotate_gear(vector<string> & gear, int target, int rotate_di){
    if(target<0 || target >3 || vi[target]==true){
        return;
    }
    vi[target]= true;
    if(check_rotate(gear, target, target+1)){
        rotate_gear(gear, target+1, -rotate_di);
    }
    if(check_rotate(gear, target, target-1)){
        rotate_gear(gear, target-1, -rotate_di);
    }
    if(rotate_di == -1){
        string temp = gear[target].substr(1);
        temp = temp + gear[target][0];
        gear[target] = temp;
    }
    else{
        string temp = gear[target].substr(0, 7);
        temp = gear[target][7] + temp;
        gear[target] = temp;
    }
}

int main(void){
    vector<string > gear;
    vector<int> ptr;
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin>>s;
        gear.push_back(s);
        ptr.push_back(0);
    }
    int k ;
    cin>>k;
    int target = 0;
    int rotate_di = 0;

    for (int i = 0; i < k; i++)
    {
        cin>>target>>rotate_di;
        int n_t = target - 1;
        memset(vi, 0, sizeof(vi));
        rotate_gear(gear, n_t, rotate_di);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if(gear[i][0]=='1'){
            ans += (1<<i);
        }
    }
    cout<<ans<<endl;
}