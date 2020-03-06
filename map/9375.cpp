#include<iostream>
#include<map>
#include<string>
#include<utility>

using namespace std;
int T;
int N;

int main(void){
    string temp, key;
    cin>>T;
    while(T>0){
        map<string, int> clothes;
        T--;
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            cin>>temp>>key;
            if(clothes.count(key)){
                clothes[key]++;
            }
            else{
                clothes.insert(make_pair(key, 1));
            }

        }
        int mul = 1;
        for(map<string, int>::iterator it = clothes.begin(); it !=clothes.end(); ++it){
            mul = mul * (it->second+1);
        }
        cout<<mul-1<<endl;
    }

    return 0;
}