#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct MicrobGroup {
	int row;
	int col;
	int num_microb;
	int dir;
	int index;
	int remove;
	MicrobGroup() {}
}MicrobGroup;

vector<MicrobGroup> group;
vector<MicrobGroup> map[101][101];

int map_size;
int end_time;
int num_group;
int dir_row[5] = {0,-1,1,0,0};
int dir_col[5] = { 0,0,0,-1,1 };
bool cmp(MicrobGroup a, MicrobGroup b) {
	return a.num_microb > b.num_microb;
}
void mapping();
void Move();
int Solve();
int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		printf("#%d %d\n" ,i, Solve());
	}
}
void mapping() {
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			map[i][j].clear();
		}
	}
	for (int i = 0; i < group.size(); i++) {
		if (group[i].remove == 1)
			continue;
		map[group[i].row][group[i].col].push_back(group[i]);
	}
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end(), cmp);
				for (int k = 1; k < map[i][j].size(); k++) {
					group[map[i][j][k].index].remove = 1;
					group[map[i][j][0].index].num_microb += map[i][j][k].num_microb;
				}
				//map[i][j].pop_back();
			}
		}
	}

}
void Move() {
	for (int i = 0; i < group.size(); i++) {//군집마다
		if (group[i].remove == 1)
			continue;
		group[i].row = group[i].row + dir_row[group[i].dir];
		group[i].col = group[i].col + dir_col[group[i].dir];
		if (group[i].dir == 1 && group[i].row == 0) {
			group[i].dir = 2;
			group[i].num_microb = group[i].num_microb/2;
		}
		else if (group[i].dir == 2 && group[i].row == map_size - 1) {
			group[i].dir = 1;
			group[i].num_microb = group[i].num_microb / 2;
		}
		else if (group[i].dir == 3 && group[i].col == 0) {
			group[i].dir = 4;
			group[i].num_microb = group[i].num_microb / 2;
		}
		else if (group[i].dir == 4 && group[i].col == map_size - 1) {
			group[i].dir = 3;
			group[i].num_microb = group[i].num_microb / 2;
		}
	}
}

int Solve() {
	//input
	MicrobGroup temp;
	scanf("%d %d %d", &map_size, &end_time, &num_group);
	group.clear();
	for (int i = 0; i < num_group; i++) {
		
		scanf("%d %d %d %d", &temp.row, &temp.col, &temp.num_microb, &temp.dir);
		temp.index = i;
		temp.remove = 0;
		group.push_back(temp);
	}
	for (int i = 0; i < end_time; i++) {
		Move();
		mapping();
	}
	int result = 0;
	for (int i = 0; i < group.size(); i++) {
		if (group[i].remove == 0)
			result += group[i].num_microb;
	}
	return result;
}