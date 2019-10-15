#include <stdio.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

typedef struct Place {
	int row;
	int col;
	int min_dist;
	Place() {}
	Place(int r, int c){
		row = r;
		col = c;
		min_dist = INT_MAX;
	}

}Place;

//먼저 치킨집을 고른다
//고른 치킨집에서 최단 거리를 구한다
//그중최소를 구한다.
int map_size, chicken_num;
int map[51][51];
vector<Place> home;
vector<Place> chicken;
int result = INT_MAX;
void update_dist(int num) {
	for (int i = 0; i < home.size(); i++) {
		int dist = abs(home[i].row - chicken[num].row) + abs(home[i].col - chicken[num].col);
		home[i].min_dist = min(home[i].min_dist, dist);
	}
}

void Select_Chicken() {
	vector<int> Select;
	for (int i = 0; i < chicken_num; i++) {
		Select.push_back(1);
	}
	for (int i = 0; i < chicken.size() - chicken_num; i++) {
		Select.push_back(0);
	}
	sort(Select.begin(), Select.end());
	do {
		for (int i = 0; i < home.size(); i++) {
			home[i].min_dist = INT_MAX;
		}

		for (int i = 0; i < Select.size(); i++) {
			if (Select[i] == 1) {
				update_dist(i);
			}
		}
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			sum += home[i].min_dist;
		}
		result = min(sum, result);
	} while (next_permutation(Select.begin(), Select.end()));
}

int main() {
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d", &map_size, &chicken_num);
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				home.push_back(Place(i, j));
			else if (map[i][j] == 2)
				chicken.push_back(Place(i, j));
		}
	}

	Select_Chicken();
	printf("%d\n", result);

}