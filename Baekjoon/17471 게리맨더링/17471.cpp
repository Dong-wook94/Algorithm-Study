#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <limits.h>
using namespace std;

typedef struct NodeInfo {
	int n_people;
	int group;
	int visited;
	NodeInfo(int p,int v,int g) {
		n_people = p;
		visited = v;
		group = g;
	}
}NodeInfo;

int min_result = INT_MAX;
int num_node;
vector<vector<int>> graph;
vector<NodeInfo> node_info;
int sum;
int flag;
int cnt_node;

void init_visited();
void check_connection(int group_size, int node, int group_name);
int check_possible();
void dfs(int index, int cnt);
int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &num_node);

	node_info.push_back(NodeInfo(0, 0,0)); //1부터시작하려고 0에아무값 넣음.
	for (int i = 0; i < num_node; i++) {
		int temp;
		scanf("%d", &temp);
		node_info.push_back(NodeInfo(temp, 0,0));
	}
	vector<int> x;
	graph.push_back(x);
	for (int i = 0; i < num_node; i++) {
		int graph_size;
		vector<int> temp;
		int input;
		scanf("%d", &graph_size);
		for (int i = 0; i < graph_size; i++) {
			scanf("%d", &input);
			temp.push_back(input);
		}
		graph.push_back(temp);
	}
	init_visited();
	dfs(1, 0);
	if (min_result == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n",min_result);
}
void init_visited() {
	for (int i = 1; i < node_info.size(); i++) {
		node_info[i].visited = 0;
	}
}

void check_connection(int group_size,int node,int group_name) {
	if (group_size == cnt_node) {
		flag = 0;
		return;
	}
	for (int i = 0; i < graph[node].size(); i++) {
		if (node_info[graph[node][i]].visited==0 && node_info[graph[node][i]].group==group_name) {
			node_info[graph[node][i]].visited = 1;
			cnt_node++;
			check_connection(group_size,graph[node][i], group_name);
		}
	}
}

int check_possible() {
	vector<int> A, B;
	int a=0;
	int b=0;
	init_visited();
	for (int i = 1; i <=num_node; i++) {
		if (node_info[i].group == 1)
			A.push_back(i);
		else {
			B.push_back(i);
		}
	}
	if (A.size() == 0 || B.size() == 0)
		return -1;
	
	flag = 1;
	node_info[A[0]].visited = 1;
	cnt_node = 1;
	check_connection(A.size(), A[0], 1);
	if (flag) {
		return -1;
	}
	flag = 1;
	node_info[B[0]].visited = 1;
	cnt_node = 1;
	check_connection(B.size(), B[0], 0);
	if (flag) {
		return -1;
	}
	for (int i = 0; i < A.size(); i++) {
		a += node_info[A[i]].n_people;
	}
	for (int i = 0; i < B.size(); i++) {
		b += node_info[B[i]].n_people;
	}
	return abs(a-b);

}

void dfs(int index,int cnt ) {
	//종료조건
	if (cnt >= 1&&cnt<num_node) //최소 1개이상의 원소만 뽑으면 계산해주니까
	{
		//나뉠수 있는지 체크후
		int val = check_possible();
		if (val>=0) {
			min_result = min(val, min_result);
		}
		//최솟값 계산
	}

	//
	for (int i = index; i <=num_node; i++) {
		if (node_info[i].group == 1) {
			continue;
		}
		node_info[i].group = 1;
		dfs(i, cnt + 1);
		node_info[i].group = 0;
	}
	
}