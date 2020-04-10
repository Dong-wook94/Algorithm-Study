#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> clothes_map;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	for (int i = 0; i < clothes.size(); i++) {
		string type=clothes[i][1];
		string name = clothes[i][0];
		clothes_map[type].push_back(name);
	}

	for (auto iter = clothes_map.begin(); iter != clothes_map.end(); iter++) {
		answer *= (iter->second.size() + 1);
	}

	answer--;//다없는 경우 빼기
	return answer;
}