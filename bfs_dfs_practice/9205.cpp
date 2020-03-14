#include <iostream>
#include <utility>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

int T, N;

int conv[100][2];
bool visited[100];
bool happy = false;
pair<int, int> home, festival;

bool can_arrive(int x, int y, int fx, int fy){
    int dx = 0;
    int dy = 0;
    dx = (x>=fx) ? x-fx : fx - x;
    dy = (y>=fy) ? y-fy : fy - y;
    if (dx + dy > 1000){
        return false;
    }
    return true;
}

void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(home.first,home.second));
    while(!q.empty()){
        auto place = q.front();
        int x = place.first;
        int y = place.second;
        if(can_arrive(x, y, festival.first, festival.second)){
            happy = true;
            return;
        }
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if(!visited[i] && can_arrive(x, y, conv[i][0], conv[i][1])){
                visited[i] = true;
                q.push(make_pair(conv[i][0], conv[i][1]));
            }
        }
    }

}

int main(void){
    cin>>T;
    
    while(T > 0){
        T--;
        // intialize
        memset(conv, 0, sizeof(conv));
        memset(visited, false, sizeof(visited));
        happy = false;
        cin>>N;
        int a, b;
        cin>>a>>b;
        home = make_pair(a,b);
        for (int i = 0; i < N; i++)
        {
            cin>>conv[i][0]>>conv[i][1];
        }
        cin>>a>>b;
        festival = make_pair(a, b);
        bfs();
        if(happy){
            cout<<"happy"<<endl;
        }
        else{
            cout<<"sad"<<endl;
        }
    }
    return 0;
}