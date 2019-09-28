#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


class Map {
private:
public:
	int nutriment;
	vector<int> trees;
};


Map map[11][11];
int nutriment[11][11];
int map_size, num_tree, year;
int dead_tree[11][11];

void spring();
void summer();
void fall();
void winter();

int row_dir[8] = {-1,-1,-1,0,0,1,1,1};
int col_dir[8] = {-1,0,1,-1,1,-1,0,1};

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
		map[r][c].trees.push_back(a);
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
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			if (!map[i][j].trees.empty()) {
				sort(map[i][j].trees.begin(), map[i][j].trees.end(),greater<int>());
				for (int k = map[i][j].trees.size()-1; k>=0; k--) {
					if (map[i][j].nutriment >= map[i][j].trees[k]) {
						map[i][j].nutriment -= map[i][j].trees[k];
						map[i][j].trees[k]++;
					}
					else {
						vector<int>::iterator iter = map[i][j].trees.begin();
						//dead_tree.push_back(map[i][j].trees[k]);
						dead_tree[i][j] += map[i][j].trees[k]/2;
						map[i][j].trees.erase(iter + k);
						num_tree--;
					}
				}
				
			}
			
		}
	}
}
void summer() {
	for (int i = 1;i<=map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			map[i][j].nutriment += dead_tree[i][j];
			dead_tree[i][j] = 0;
		}
		
	}

}
void fall() {//나무번식
	for (int r = 1; r <= map_size; r++) {
		for (int c = 1; c <= map_size; c++) {
			for (int t = 0; t < map[r][c].trees.size(); t++) {
				if (map[r][c].trees[t]%5==0&&map[r][c].trees[t]>0)
					for (int i = 0; i < 8; i++) {
						int next_row = r + row_dir[i];
						int next_col = c + col_dir[i];
						if (next_row <= 0 || next_col <= 0 || next_row > map_size || next_col > map_size)
							continue;
						map[next_row][next_col].trees.push_back(1);
						num_tree++;
					}
			}
			
		}
	}
}
void winter(){
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			map[i][j].nutriment += nutriment[i][j];
		}
	}
}