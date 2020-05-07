#include <string>
#include <vector>
#include <set>

using namespace std;
int n_column;
int mask;

bool isUnique(int bit,vector<vector<string>> relation){
    set<vector<string>> check_set;
    for(int i=0;i<relation.size();i++){
        vector<string> keys;
        for(int j=0;j<n_column;j++){
            if(bit &(mask>>j)){//넣는곳일때
                keys.push_back(relation[i][j]);
            }
        }
        check_set.insert(keys);
    }
    if(relation.size() == check_set.size())
        return true;
    return false;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    n_column = relation[0].size();
    mask = 1<<(n_column-1);
    
    vector<int> uniques;
    vector<bool> check_minimality;
    
    for(int i=1;i<(1<<n_column);i++){
        if(isUnique(i, relation))
            uniques.push_back(i);
    }
    
    check_minimality.assign(uniques.size(), true);
    
    for(int i=0;i<uniques.size()-1;i++){
        for(int j=i+1;j<uniques.size();j++){
            if(uniques[i]==(uniques[i]&uniques[j])){//uniques[i]가 부분집합일때
                check_minimality[j] = false;
            }
            else if(uniques[j]==(uniques[i]&uniques[j])){//uniques[j]가 부분집할일때
                check_minimality[i] = false;
            }
        }
    }
    
    for(int i=0;i<check_minimality.size();i++){
        if(check_minimality[i])
            answer++;
    }
    
    return answer;
}
