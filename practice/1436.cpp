#include <iostream>
#include <string>

using namespace std;

int main(void){
    long long start = 666;
    int cnt = 0;
    int n;
    cin>>n;
    while(cnt != n){
        string s = to_string(start);
        if(s.find("666")!= -1){ 
            cnt++;
        }
        start++;
    }
    cout<<start-1<<endl;
}