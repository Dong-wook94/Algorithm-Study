#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct Trie* TriePointer;
typedef struct Trie{
    TriePointer next[26];
    int count;
    bool finish;
    Trie(){
        finish = false;
        count = 1;
        memset(next,0,sizeof(next));
    }
    ~Trie(){
    }
    void insert(const char* key){//삽입시 finish처리, 카운트처리
        if(*key == '\0') //입력끝일때
            finish = true;
        else{
            int curr = *key - 'a';
            if(next[curr]==NULL){
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
        if(*key == '?'){ //물음표 나오면 아래 가지에있는 카운트 다더하면됨.
            int temp = 0;
            for(int k=0;k<26;k++){
                if(next[k]!=NULL){
                    temp += next[k]->count;
                }
            }
            return temp;
        }
        if(next[curr] == NULL)return 0;
        if(*(key+1)=='?') return next[curr]->count;
        
        return next[curr]->find(key+1);
    }
}Trie;

//글자수 별로 다로 저장한다.
TriePointer root[10001];
TriePointer reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    answer.assign(queries.size(), 0);
    
    for(int i=0;i<words.size();i++){
        string word = words[i];
        int size = word.size();
        
        const char *c = word.c_str();
        if(root[size]==NULL)
            root[size] = new Trie();
        root[size]->insert(c);
        
        string reversed_string = word;
        reverse(reversed_string.begin(), reversed_string.end());
        const char *k = reversed_string.c_str();
        if(reroot[size]==NULL)reroot[size] = new Trie();
        reroot[size]->insert(k);
    }
    
    int idx = 0;
    
    for(int i=0;i<queries.size();i++){
        string query = queries[i];
        int size = query.size();
        if(query[size-1]=='?'){ //끝이 물음표일때
            const char *c = query.c_str();
            if(root[size] == NULL){
                idx++;
                continue;
            }
            else{
                answer[idx] = root[size]->find(c);
            }
        }
        else{
            string re = query;
            reverse(re.begin(),re.end());
            const char *k = re.c_str();
            if(reroot[size] ==NULL){
                idx++;
                continue;
            }
            else{
                answer[idx]= reroot[size]->find(k);
            }
            
        }
        idx++;
    }
    return answer;
}
