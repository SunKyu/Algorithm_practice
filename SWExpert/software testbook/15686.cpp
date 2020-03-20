//https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
#include <utility>
#define MAX 50

using namespace std;

int N;
int M;
int city[MAX][MAX];
bool bhc[13];
bool house[MAX*2];
int house_cnt = 0;
int bhc_cnt = 0;
int ans = 9999999;
vector<pair<int, int> > houses;
vector<pair<int, int> > bhcs;

void dfs(int bhc_at,int cnt){
    if(cnt == M){
        //1.get chicken distance
        //2.pick minvalue  new chicken distance with old ans
        int city_chicken_dis = 0;
        for (int i = 0; i < house_cnt; i++)
        {
            int min_chicken_dis = -1;
            for (int j = 0; j < bhc_cnt; j++)
            {
                if (!bhc[j])
                {
                    continue;
                }
                int dis = abs(bhcs[j].first - houses[i].first);
                dis+= abs(bhcs[j].second - houses[i].second);
                if(min_chicken_dis == -1){
                    min_chicken_dis = dis;
                } else{
                    min_chicken_dis = min(dis, min_chicken_dis);
                }
            }
            city_chicken_dis+= min_chicken_dis;
        }
        ans = min(city_chicken_dis, ans);
    } else{
        for (int i = bhc_at+1; i < bhc_cnt; i++)
        {
            if (!bhc[i])
            {
                bhc[i] = true;
                dfs(i, cnt+1);
                bhc[i] = false;
            }
        }
    }
}

int main(void){
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>city[i][j];
            switch (city[i][j])
            {
            case 1:
                house_cnt++;
                houses.push_back(make_pair(i, j));
                break;
            case 2:
                bhc_cnt++;
                bhcs.push_back(make_pair(i, j));
                break;
            default:
                break;
            }
        }
    }
    dfs(-1, 0);
    cout<<ans<<endl;
    return 0;
}