#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef struct Person {
	int index;
	int row;
	int col;
	int dist[2];
	Person() {}
	Person(int i, int r, int c) {
		index = i;
		row = r;
		col = c;
	}
}Person;

typedef struct Stair {
	int length;
	int row;
	int col;
	queue<Person> stair_q;
	vector<Person> wait;
	Stair() {}
	Stair(int l, int r, int c) {
		length = l;
		row = r;
		col = c;
	}
}Stair;

vector<Stair> stair;
vector<Person> person;
int min_result;
int map_size;
int map[11][11];
int Select[11];
bool cmp0(Person a, Person b) {
	return a.dist[0] > b.dist[0];
}
bool cmp1(Person a, Person b) {
	return a.dist[1] > b.dist[1];
}
int lunch() {
	for (int i = 0; i < person.size(); i++) {
		if (Select[i] == 0) {
			stair[0].wait.push_back(person[i]);
		}
		else {
			stair[1].wait.push_back(person[i]);
		}
	}
	sort(stair[0].wait.begin(), stair[0].wait.end(), cmp0);
	sort(stair[1].wait.begin(), stair[1].wait.end(), cmp1);
	int result = 0;
	for (int i = 0; i < 2; i++) {
		Person temp;
		int wait_time = 0;
		if (stair[i].wait.empty())
			continue;
		while (!stair[i].wait.empty()) {
			while (stair[i].stair_q.size() < 3) {
				if (stair[i].wait.empty()) {
					while (!stair[i].stair_q.empty())
						stair[i].stair_q.pop();
					break;
				}
				temp = stair[i].wait[stair[i].wait.size() - 1];
				stair[i].wait.pop_back();
				stair[i].stair_q.push(temp);
			}
			if (stair[i].wait.empty()) {
				while (!stair[i].stair_q.empty())
					stair[i].stair_q.pop();
				break;
			}
			if (stair[i].stair_q.front().dist[i] + stair[i].length < stair[i].wait[stair[i].wait.size() - 1].dist[i]) {
				stair[i].stair_q.pop();
			}
			else {
				stair[i].wait[stair[i].wait.size() - 1].dist[i] += (stair[i].stair_q.front().dist[i] + stair[i].length - stair[i].wait[stair[i].wait.size() - 1].dist[i]);
				stair[i].stair_q.pop();
			}
		}
		result = max(result, temp.dist[i] + stair[i].length);
	}
	return result;
}


void dfs(int idx) {
	if (idx == person.size()) {//경우의수 구했을때
		min_result = min(min_result, lunch() + 1);
		return;
	}
	for (int i = 0; i < 2; i++) {
		Select[idx] = i;
		dfs(idx + 1);
	}
}


void Testcase() {

	scanf("%d", &map_size);

	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {//사람일때
				person.push_back(Person(person.size(), i, j));
			}
			else if (map[i][j] == 0)
				continue;
			else {//계단일때
				stair.push_back(Stair(map[i][j], i, j));
			}
		}
	}

	for (int i = 0; i < person.size(); i++) {//거리계산
		person[i].dist[0] = abs(person[i].row - stair[0].row) + abs(person[i].col - stair[0].col);
		person[i].dist[1] = abs(person[i].row - stair[1].row) + abs(person[i].col - stair[1].col);
	}
	min_result = INT_MAX;
	dfs(0);

	person.clear();
	stair.clear();
}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		Testcase();
		printf("#%d %d\n", i, min_result);
	}
}