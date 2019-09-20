#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
	int num;
	int distance;
	Node(){}
	Node(int n,int d) {
		num = n;
		distance = d;
	}
}Node;
queue<Node> q;
vector<int> visited;
int max_distance=0;
void bfs( vector<vector<int>> graph) {
	Node cur;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur.num].size();i++) {
			if (visited[graph[cur.num][i]] == -1) {
				visited[graph[cur.num][i]] = cur.distance+1;
				if (cur.distance+1 > max_distance)
					max_distance = cur.distance+1;

				q.push(Node(graph[cur.num][i], cur.distance + 1));
			}
		}
	}

}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	vector<vector<int>> graph;
	visited.assign(n+1, -1);
	//그래프생성
	graph.assign(n+1, vector<int>(0, 0));
	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}
	q.push(Node(1,0));
	visited[1] = 0;
	bfs(graph);
	
	for (int i = 2; i <=n; i++) {
		if (visited[i] == max_distance)
			answer++;
	}
	return answer;
}

int main() {
	printf("%d", solution(6,{ {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} }));
}