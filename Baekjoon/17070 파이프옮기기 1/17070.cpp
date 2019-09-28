#include <iostream>
#include <vector>



int map[17][17];
int map_size;
int cnt = 0;
int check_possible(int row, int col,int dir, int n_case) {
	if (n_case == 2) {//대각선모양으로
		if (row + 1 > map_size || col + 1 > map_size)
			return -1;
		if (map[row + 1][col] == 0 && map[row][col + 1] == 0 && map[row + 1][col + 1] == 0)
			return 2;
		return -1;
	}
	else if (n_case == 0) {//가로모양으로
		if (col + 1 > map_size)
			return -1;
		if (map[row][col + 1] == 0)
			return 0;
		 return -1;
	}
	else {//세로모양으로
		if (row + 1 > map_size)
			return -1;
		if (map[row+1][col] == 0)
			return 1;
		return -1;
	}
}

void dfs(int row, int col ,int dir) {
	if (row == map_size && col == map_size) {
		cnt++;
		return;
	}
		
	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1)
			continue;
		if (dir == 1 && i == 0)
			continue;
		if (check_possible(row,col,dir, i)!=-1) {
			if (i == 2)
				dfs(row + 1, col + 1, i);
			else if (i == 0)
				dfs(row, col + 1, i);
			else
				dfs(row + 1, col, i);
		}
		

	}
	
}
int main() {
	scanf("%d", &map_size);
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(1, 2, 0);
	printf("%d", cnt);
}

