//https://programmers.co.kr/learn/courses/30/lessons/42889
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
bool cmp(pair<double, int> a, pair<double, int> b){
    if(a.first>b.first){
        return true;
    }else if(a.first == b.first){
        if(a.second<b.second){
            return true;
        }
        return false;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int people = stages.size();
    vector<pair< double, int> > failure;
    sort(stages.begin(), stages.end());
    for (int i = 1; i <= N; i++)
    {
        int count = 0;
        int challange_count = 0;
        for (int j = 0; j < stages.size(); j++)
        {
            if(stages[j]>i){
                count++;
            }
            else if(stages[j] == i){
                count++;
                challange_count++;
            }
        }
        double fail;
        if(count == 0){
            fail = 0;
        }else{
            fail = double(challange_count)/double(count);
        }
        failure.push_back(make_pair(fail, i));
    }
    sort(failure.begin(), failure.end(), cmp);
    
    for(const auto a: failure){
        answer.push_back(a.second);
    }
    
    return answer;
}