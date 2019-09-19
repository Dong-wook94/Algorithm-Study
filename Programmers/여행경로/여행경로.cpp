#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


void dfs(string dest, vector<vector<string>> &tickets, vector<string> &answer,int cnt) {
	
	if (answer.size() == ticket_num) {
		return;
	}
	int flag = 0;
	for (int i = 0; i < tickets.size(); i++) {
	
		if (tickets[idx][1] == tickets[i][0] && visited[0] == 0) {//µÚ¿¡¿Ã²¨
			flag = 1;
			visited[i] = 1;
			dfs(i, tickets);
			visited[i] = 0;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets,int cnt) {
	vector<int> visited;
	vector<string> answer;
	visited.assign(tickets.size(), 0);
	sort(tickets.begin(), tickets.end());
	answer.push_back(tickets[0][0]);
	dfs(tickets[0][1], tickets, visited, answer,0);

	
	return answer;
}