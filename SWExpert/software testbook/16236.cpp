//https://www.acmicpc.net/problem/16236

#include <iostream>
#include <vector>
#include <utility>
#define MAX 20

using namespace std;

int N;
int pond[MAX][MAX] = {0, };
int x;
int y;
int size = 2;
int ans = 0;
vector<pair<pair<int, int>, int> > fishes;
int main(void){
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>pond[i][j];
            if(pond[i][j] == 9){
                x = i;
                y = j;
            } else if(pond[i][j] != 0){
                pair<pair<int, int>, int>  fish;
                fish.first.first = i;
                fish.first.second = j;
                fish.second = pond[i][j];
                fishes.push_back(fish);
            }
        }
    }
    if(fishes.size() == 0){
        cout<<"0"<<endl;
        return 0;
    }
    int eat_count = 0;
    while (!fishes.empty())
    {
        int distance = 100;
        int at = 0;
        int at_x = 0;
        int at_y = 0;
        for (int i = 0; i < fishes.size(); i++)
        {
            auto fish = fishes[i];
            if(fish.second<size){
                int fish_x = fish.first.first;
                int fish_y = fish.first.second;
                int tmp_dis = 0;
                tmp_dis += fish_x > x ? fish_x - x : x - fish_x;
                tmp_dis += fish_y > y ? fish_y - y : y - fish_y;
                if(tmp_dis<distance){
                    cout<<endl<<"****"<<endl;
                    cout<<tmp_dis<<endl;
                    distance = tmp_dis;
                    at = i;
                    at_x = fish_x;
                    at_y = fish_y;
                }
            }
        }
        if (distance!=100){
            x = at_x;
            y = at_y;
            fishes.erase(fishes.begin()+at);
            eat_count++;
            ans += distance;
            if(eat_count==2){
                eat_count=0;
                size++;
            }
        }
        else{
            break;
        }
    }
    cout << ans << endl;

    return 0;
}