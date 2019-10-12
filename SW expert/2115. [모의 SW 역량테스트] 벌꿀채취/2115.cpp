#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int map[10][10];
int map_size;
int select_size;
int max_volume;
int visited[10][10];
int max_profit[2];
int result = 0;

bool check_get_possible(int row, int col) {
	for (int i = 0; i < select_size; i++) {
		if (visited[row][col + i] == 1)
			return false;
	}
	return true;
}

void MaxProfit(vector<int> honey,int index,int check_sum,int profit,int order) {
	max_profit[order] = max(max_profit[order], profit);
	if (index >= select_size) {
		
		return;
	}
	if (check_sum + honey[index] <= max_volume) {
		MaxProfit(honey, index + 1, check_sum + honey[index], profit + pow(honey[index], 2), order);
		MaxProfit(honey, index + 1, check_sum, profit, order);
	}
}
void dfs(vector<vector<int>> bucket) {
	if (bucket.size() == 2) {//종료조건
		for (int i = 0; i < bucket.size(); i++) {
			max_profit[i] = 0;
			MaxProfit(bucket[i], 0, 0, 0, i);
		}
		result = max(result, max_profit[0] + max_profit[1]);
		return;
	}
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j <= map_size - select_size; j++) {
			if (check_get_possible(i,j)) {
				vector<int> temp;
				for (int k = 0; k < select_size; k++) {
					visited[i][j + k] = 1;
					temp.push_back(map[i][j + k]);
				}
				bucket.push_back(temp);
				dfs(bucket);
				bucket.pop_back();
				for (int k = 0; k < select_size; k++) {
					visited[i][j + k] = 0;
				}
			}
		}
	}
}


void Testcase() {
	scanf("%d %d %d", &map_size, &select_size, &max_volume);
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j < map_size; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	vector<vector<int>> honey_bucket;
	dfs(honey_bucket);

}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		result = 0;
		Testcase();
		printf("#%d %d\n", i, result);
	}
}