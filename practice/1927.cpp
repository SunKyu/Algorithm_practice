#include<iostream>
#include<queue>

using namespace std;
int N;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    priority_queue<int, vector<int>, greater<int> > pq;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin>>a;
        if(a==0){
            if(pq.empty()){
                cout<<0<<'\n';
                continue;
            }
            cout<<pq.top()<<'\n';
            pq.pop();
            continue;
        }
        pq.push(a);
    }
   return 0; 
}