#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int N;
int main(void)
{
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq;
    priority_queue<int, vector<int>, less<int> > mq;

    int a;
    int p;
    int m;
    int ap;
    int am;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a < 0)
        {
            mq.push(a);
        }
        else if (a > 0)
        {
            pq.push(a);
        }
        else if (a == 0)
        {
            if (pq.empty() && mq.empty())
            {
                cout<<0<<'\n';
                continue;
            }
            if(pq.empty()){
                m = mq.top();
                mq.pop();
                cout<<m<<'\n';
                continue;
            }
            if(mq.empty()){
                p = pq.top();
                pq.pop();
                cout<<p<<'\n';
                continue;
            }
            m = mq.top();
            p = pq.top();
            ap = abs(p);
            am = abs(m);
            if (am == ap)
            {
                mq.pop();
                cout<<m<<'\n';
                continue;
            }
            if (am < ap)
            {
                mq.pop();
                cout<<m<<'\n';
                continue;
            }
            if (ap < am)
            {
                pq.pop();
                cout<<p<<'\n';
                continue;
            }
        }
    }
    return 0;
}