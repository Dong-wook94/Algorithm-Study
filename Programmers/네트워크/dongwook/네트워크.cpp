#include <string>
#include <vector>

using namespace std;

vector<int> visited;
void dfs(int num, int size, vector<vector<int>> computers);
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	visited.assign(n,0);
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			dfs(i, n, computers);
			answer++;
		}
			
	}
	
	return answer;
}
void dfs(int num,int size, vector<vector<int>> computers) {
	visited[num] = 1;

	for (int i = 0; i < size; i++) {
		if (visited[i]==0 &&computers[num][i] == 1 )
			dfs(i, size, computers);
	}
}