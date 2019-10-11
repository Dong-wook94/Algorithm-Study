#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int map_size;
int map[20][20];
int visited[101];
int max_result=0;
int dir_row[4] = {-1,1,1,-1};
int dir_col[4] = {1,1,-1,-1};

void dfs(int row, int col, int dir, int sr, int sc, int cnt,int N) {
	//종료조건
	if (dir == 4) {
		if (row == sr && col == sc&&cnt>=4) {
			max_result = max(max_result, cnt);
			return;
		}
	}


	int next_row = row + dir_row[dir];
	int next_col = col + dir_col[dir];
	if ((next_row < 0 || next_col < 0 || next_row >= N || next_col >= N))//범위체크
		return;
	else {
		if (visited[map[next_row][next_col]] == 0) {//방문안했던 숫자일때
			visited[map[next_row][next_col]] = 1;
			dfs(next_row, next_col, dir, sr, sc, cnt + 1, N);
			dfs(next_row, next_col, dir+1, sr, sc, cnt + 1, N);
			visited[map[next_row][next_col]] = 0;
		}
		else {
			dfs(row, col, dir+1, sr, sc, cnt, N);
		}
	}
}

void Testcase() {
	scanf("%d", &map_size);
	for(int i=0;i<map_size;i++){
		for (int j = 0; j < map_size; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int sr = 1; sr < map_size - 1; sr++) {
		for (int sc = 0; sc < map_size - 2; sc++) {
			memset(visited, 0, sizeof(visited));
			visited[map[sr][sc]] = 1;
			dfs(sr, sc, 0, sr+1, sc+1, 1, map_size);
			visited[map[sr][sc]] = 0;
		}
	}

}
int main() {
	int testcase;
//	freopen("input.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		max_result = 0;
		Testcase();
		if (max_result == 0)
			max_result = -1;
		printf("#%d %d\n", i,max_result);
	}
}