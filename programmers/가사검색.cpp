//https://programmers.co.kr/learn/courses/30/lessons/60060
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie
{
    Trie* next[26];
    int count;
    bool term;
    Trie() : term(false), count(1){
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for(int i = 0; i<26; i++){
            if(next[i])
                delete next[i];
        }
    }
    void insert(const char* key){
        if(*key == '\0')
            term =true;
        else{
            int curr = *key -'a';
            if(next[curr] == NULL){
                next[curr] = new Trie();
            }
            else{
                next[curr]->count++;
            }
            next[curr]->insert(key+1);
        }
    }
    int find(const char* key){
        int curr = *key -'a';
        if(*key == '?'){
            int tmp = 0;
            for(int k =0 ; k<26; k++){
                if(next[k] != NULL){
                    tmp += next[k]->count;
                }
            }
            return tmp;
        }
        if(next[curr] == NULL){
            return 0;
        }
        if(*(key+1) == '?') return next[curr]->count;
    }
};


vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 0; i < queries.size(); i++)
    {
        string query = queries[i];
        int count = 0;
        for (int j = 0; j < words.size(); j++)
        {
            string word  = words[j];
            if(query.length()==word.length()){
                bool flag = true;
                for (int k = 0; k < query.length(); k++)
                {
                    if(query[k]!=word[k] && query[k]!='?'){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    count++;
                }
                
            }
        }
        answer.push_back(count);
    }
    return answer;
}