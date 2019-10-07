
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int paper_cnt[6];
int total_cnt = 0;
int min_result=100;
int one_cnt = 0;
int change_cnt = 0;
int map[10][10];

void fill(int r, int c, int p_size, int val);
void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				one_cnt++;
		}
	}
	for (int i = 1; i <= 5; i++) {
		paper_cnt[i] = 5;
	}
}
int Check_paper(int row, int col, int p_size) {
	if (row + p_size > 10 || col + p_size > 10)return 0;
	for (int i = row; i <row+ p_size; i++) {
		for (int j = col; j < col+p_size; j++) {
			if (map[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

void dfs(int index, int cnt){
	if (index==100) {
		min_result = min(min_result, cnt);
		return;
	}
	int row = index / 10;
	int col = index % 10;
	
	if (min_result <= cnt)
		return;

	if (map[row][col] == 1) {
		for (int i = 5; i > 0; i--) {
			if (paper_cnt[i] > 0) {
				if (Check_paper(row, col, i)) {
					fill(row, col, i, 0);
					paper_cnt[i]--;
					dfs(index + 1, cnt + 1);
					fill(row, col, i, 1);
					paper_cnt[i]++;
				}
			}
		}
	}
	else {
		dfs(index + 1, cnt);
	}
}

int main() {
	init();
	for (int i = 5; i > 0; i--) {
		dfs(0, 0);
	}
	if (min_result==100)
		printf("-1");
	else {
		printf("%d", min_result);
	}
	

}
void fill(int r, int c, int p_size, int val) {
	for (int i = r; i < r + p_size; i++) {
		for (int j = c; j < c + p_size; j++) {
			map[i][j] = val;
			if (val == 1) {
				change_cnt--;
			}
			else {
				change_cnt++;
			}
		}
	}
}