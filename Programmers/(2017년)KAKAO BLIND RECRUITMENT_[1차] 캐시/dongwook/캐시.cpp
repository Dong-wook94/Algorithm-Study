#include <string>
#include <vector>
#include <string.h>

using namespace std;
typedef struct Cache {
	int time;
	string data;
	Cache() {}
	Cache(int t, string d) {
		time = t;
		data = d;
	}
}Cache;

vector<Cache> memory;
int LRU(string city);
int cnt = 0;
int min_time = 100000;
int solution(int cacheSize, vector<string> cities);
int main() {
	vector<string> ex1= { "Jeju", "Pangyo", "NewYork", "newyork" };
	
	printf("%d", solution(ex1.size(), ex1));

}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	
	if (cacheSize == 0)
		return cities.size()*5;
	memory.assign(cacheSize, Cache(-1,""));
	for (int i = 0; i < cities.size(); i++) {
		answer += LRU(cities[i]);
		cnt++;
	}

	return answer;
}
int LRU(string city) {
	int LRU_index=0;
	for (int i = 0; i < city.size(); i++) {
		if (city[i] <= 'Z' && city[i] >= 'A')
			city[i] = city[i] - ('A' - 'a');
	}

	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].data.compare(city)== 0) {
			//LRU_index = i;
			memory[i].time = cnt;
			return 1;
		}
	}
	for (int i = 0; i < memory.size(); i++) {
		if (memory[i].time < min_time) {
			LRU_index = i;
			min_time = memory[i].time;
		}
	}
	memory[LRU_index].time = cnt;
	min_time = cnt;
	memory[LRU_index].data = city;
	
	return 5;
}