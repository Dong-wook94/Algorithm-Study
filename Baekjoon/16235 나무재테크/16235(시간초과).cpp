#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Pos {
public:
	int row;
	int col;
	Pos() {}
	Pos(int r, int c) {
		row = r;
		col = c;
	}
};
class Tree {
private:
public:
	int row;
	int col;
	int age;
	Tree() {}
	Tree(int a) {
		age = a;
	}
	Tree(int r, int c, int a) {
		row = r;
		col = c;
		age = a;
	}
};
class Map {
private:
public:
	int nutriment;
	vector<Tree> trees;
};


Map map[11][11];
int nutriment[11][11];
int map_size, num_tree, year;
vector<Pos> tree_exist;
vector<Tree> dead_tree;
vector<Tree> will_breed;
void spring();
void summer();
void fall();
void winter();

int row_dir[8] = { -1,-1,-1,0,0,1,1,1 };
int col_dir[8] = { -1,0,1,-1,1,-1,0,1 };
bool cmp(Tree a, Tree b) {
	return a.age > b.age;
}
int main() {
	scanf("%d %d %d", &map_size, &num_tree, &year);
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			scanf("%d", &nutriment[i][j]);
			map[i][j].nutriment = 5;
		}
	}
	for (int i = 0; i < num_tree; i++) {
		int r, c, a;
		scanf("%d %d %d", &r, &c, &a);
		map[r][c].trees.push_back(Tree(r, c, a));
		tree_exist.push_back(Pos(r, c));
	}
	for (int i = 0; i < year; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	printf("%d", num_tree);
}

void spring() {//나이만큼 양분먹고 나이 1증가
	for (int i = 0; i < tree_exist.size(); i++) {
		sort(map[tree_exist[i].row][tree_exist[i].col].trees.begin(), map[tree_exist[i].row][tree_exist[i].col].trees.end(), cmp);
		for (int j = map[tree_exist[i].row][tree_exist[i].col].trees.size() - 1; j >= 0; j--) {
			Tree temp = map[tree_exist[i].row][tree_exist[i].col].trees[j];
			if (map[tree_exist[i].row][tree_exist[i].col].nutriment >= temp.age) {
				map[tree_exist[i].row][tree_exist[i].col].nutriment -= temp.age;
				map[tree_exist[i].row][tree_exist[i].col].trees[j].age++;
				if (map[tree_exist[i].row][tree_exist[i].col].trees[j].age % 5 == 0 && map[tree_exist[i].row][tree_exist[i].col].trees[j].age > 0) {
					will_breed.push_back(map[tree_exist[i].row][tree_exist[i].col].trees[j]);
				}
			}
			else {
				vector<Tree>::iterator iter = map[tree_exist[i].row][tree_exist[i].col].trees.begin();
				dead_tree.push_back(map[tree_exist[i].row][tree_exist[i].col].trees[j]);
				map[tree_exist[i].row][tree_exist[i].col].trees.erase(iter + j);
				num_tree--;
				if (map[tree_exist[i].row][tree_exist[i].col].trees.size() == 0) {
					tree_exist.erase(tree_exist.begin() + i);
					i--;
				}
			}

		}



	}
}
void summer() {
	for (int i = 0; i < dead_tree.size(); i++) {
		map[dead_tree[i].row][dead_tree[i].col].nutriment += (dead_tree[i].age / 2);
	}
	dead_tree.clear();
}
void fall() {//나무번식
	for (int i = 0; i < will_breed.size(); i++) {
		for (int j = 0; j < 8; j++) {
			int next_row = will_breed[i].row + row_dir[j];
			int next_col = will_breed[i].col + col_dir[j];
			if (next_row <= 0 || next_col <= 0 || next_row > map_size || next_col > map_size)
				continue;
			if (map[next_row][next_col].trees.size() == 0)
				tree_exist.push_back(Pos(next_row, next_col));
			map[next_row][next_col].trees.push_back(Tree(next_row, next_col, 1));
			num_tree++;
		}
	}
	will_breed.clear();
}
void winter() {
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			map[i][j].nutriment += nutriment[i][j];
		}
	}
}