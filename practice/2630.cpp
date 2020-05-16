#include<iostream>

using namespace std;


int N;
int M[128][128];
int ans_b = 0;
int ans_w = 0;

void divide(int size, int x, int y){
    int color = M[x][y];
    for (int i = x; i < x+size; i++)
    {
        for (int j = y; j < y+size; j++)
        {
            if(color!=M[i][j]){
                divide(size/2, x, y);
                divide(size/2, x+size/2, y);
                divide(size/2, x, y+size/2);
                divide(size/2, x+size/2, y+size/2);
                return;
            }
        }
    }
    if(color == 1){
        ans_b++;
    }
    else{
        ans_w++;
    }
    return;
}

int main(void){
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>M[i][j];
        }
    }
    divide(N, 0, 0);
    cout<<ans_w<<endl;
    cout<<ans_b<<endl;
    
}