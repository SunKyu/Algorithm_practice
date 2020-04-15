#include <iostream>

using namespace std; 

int main(void){
    int n;
    int ans;
    cin>>n;
    int c = 1;
    int tmp = 1;
    int sum = 0;
    while(1){
        tmp = c;
        sum = c;
        while(tmp){
            sum+= tmp%10;
            tmp = tmp/10;
        }
        if(sum == n || c == n){
            break;
        }
        c++;
    }
    if (c == n)
    {
        cout << 0 << endl;
        return 0;
    }
    cout<<c<<endl;
    return 0;
}