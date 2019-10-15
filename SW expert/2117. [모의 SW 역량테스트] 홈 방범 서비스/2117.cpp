#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct House {
	int row;
	int col;
	int dist;
	House(){}
	House(int r, int c){
		row = r;
		col = c;
	}
}House;

int map_size, cost;
int map[21][21];
int operate_cost[41];
int result=0;
vector<House> house;
bool cmp(House a, House b) {
	return a.dist < b.dist;
}

void Calculate(int row,int col) {
	for (int i = 0; i < house.size(); i++) {
		house[i].dist = abs(house[i].row - row) + abs(house[i].col - col);
	}
	sort(house.begin(), house.end(), cmp);//sort
	
	for (int i = 0; i < house.size(); i++) {//
		
		if (i + 1 == house.size()) {
			int profit = cost * (i+1) - operate_cost[house[i].dist+1];
			if (profit >=0) {
				result = max(result,i + 1);
			}
		}
		else if (house[i].dist < house[i + 1].dist) {
			int profit = cost * (i + 1) - operate_cost[house[i].dist+1];
			if (profit >=0) {
				result = max(result, i + 1);
			}
			
		}
	}
}
void Testcase() {
	result = 0;
	scanf("%d %d", &map_size, &cost);
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				house.push_back(House(i, j));
			}
		}
	}
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			Calculate(i, j);
		}
	}
	
}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	for (int i = 1; i < 41; i++) {
		operate_cost[i] = i * i + (i - 1)*(i - 1);
	}
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		Testcase();
		printf("#%d %d\n", i, result);
		house.clear();
	}
}