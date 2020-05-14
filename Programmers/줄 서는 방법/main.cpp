#include <string>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> people;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    long long factorial = 1;
    for(int i=1;i<=n;i++){
        factorial *=i;
        people.push_back(i);
    }
    
    k--;
    
    while(n>0){
        factorial/=n;
        n--;
        answer.push_back(people[k/factorial]);
        people.erase(people.begin() + k/factorial);
        k %= factorial;
    }
    return answer;
}
