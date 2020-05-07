#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

typedef struct Cache{
    int time;
    string data;
    Cache(){}
    Cache(int t,string d){
        time =t;
        data = d;
    }
}Cache;

vector<Cache> memory;
int min_time = INT_MAX;
string changeLowerCaseStr(string city){
    for(int i=0;i<city.size();i++){
        if(city[i] <='Z' && city[i] >='A')
            city[i] = city[i] -('A'-'a');
    }
    return city;
}

int LRU(string city,int cnt){
    int LRU_index=0;
    city = changeLowerCaseStr(city);
    
    for(int i=0; i<memory.size();i++){
        if(memory[i].data == city){//hit
            memory[i].time = cnt;
            return 1;
        }
    }
    for(int i=0;i<memory.size();i++){
        if(memory[i].time < min_time){//제일 시간 적은애부터
            LRU_index = i;
            min_time = memory[i].time;
        }
    }
    memory[LRU_index].time = cnt;
    min_time = cnt;
    memory[LRU_index].data = city;
    
    return 5;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize ==0)
        return cities.size()*5;
    memory.assign(cacheSize,Cache(-1,""));
    for(int i=0;i<cities.size();i++){
        answer += LRU(cities[i],i);
        //cout<<answer<<endl;
    }
    return answer;
}

int main() {
    vector<string> ex1= { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    printf("%d", solution(3, ex1));

}
