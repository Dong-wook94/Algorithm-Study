#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> parent;
int col_find(int n);
void wei_union(int i, int j);

bool cmp(vector<int> a, vector<int>b);

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	parent.assign(n, -1);
	sort(costs.begin(), costs.end(), cmp);
	for (int i = 0; i < costs.size(); i++) {
		int v = col_find(costs[i][0]);
		int u = col_find(costs[i][1]);

		if (v != u) {
			wei_union(v, u);
			cout << costs[i][0] << "," << costs[i][1] << ":" << costs[i][2] << endl;
			answer += costs[i][2];
		}
	}

	return answer;
}
bool cmp(vector<int> a, vector<int>b) {
	return a[2] < b[2];
}

int col_find(int n) {//루트를 찾음
	int root;

	for (root = n; parent[root] >= 0; root = parent[root]) {}

	for (int i = n; i != root; i = parent[i]) {
		parent[i] = root;
	}

	return root;
}

void wei_union(int i, int j) {
	int temp;

	temp = parent[i] + parent[j];

	if (parent[i] > parent[j]) {
		parent[i] = j;
		parent[j] = temp;
	}
	else {
		parent[j] = i;
		parent[i] = temp;
	}
}
