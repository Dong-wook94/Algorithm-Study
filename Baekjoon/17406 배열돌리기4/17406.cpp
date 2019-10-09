#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

typedef struct RotateInfo {
	int row;
	int col;
	int size;
}RotateInfo;

RotateInfo rotate_info[7];
int N, M, K;
int A[51][51];

int result = INT_MAX;
int dir_row[4] = {1,0,-1,0};
int dir_col[4] = { 0,1,0,-1 };
int visited[7];
void Copymap(int a[][51], int b[][51]) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			a[i][j] = b[i][j];
		}
	}
}
void print_map() {
	printf("\nmap출력 \n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}
int check_edge(int next_row, int next_col, int row, int col, int rotate_size) {
	if (next_row == row + rotate_size && next_col == col + rotate_size) {
		return 1;
	}
	else if (next_row == row - rotate_size && next_col == col + rotate_size) {
		return 1;
	}
	else if (next_row == row - rotate_size && next_col == col - rotate_size) {
		return 1;
	}
	else if (next_row == row + rotate_size && next_col == col - rotate_size) {
		return 1;
	}
	else {
		return 0;
	}
}
void move_array(int row, int col, int rotate_size) {
	for (int i = 1; i <= rotate_size; i++) {
		int temp = A[row - i][col - i];
		int d = 0;
		int cur_row = row - i;
		int cur_col = col - i;
		int next_row = cur_row + dir_row[d];
		int next_col = cur_col + dir_col[d];
		while (1) {
			if (next_row == row - i && next_col == col - i) {
				A[cur_row][cur_col] = temp;
				break;
			}
			A[cur_row][cur_col] = A[next_row][next_col];
			//print_map();
			cur_row = next_row;
			cur_col = next_col;
			next_row = cur_row + dir_row[d];
			next_col = cur_col + dir_col[d];
			if (check_edge(next_row, next_col, row, col, i)) {
				d = (d + 1) % 4;
			}
		}
	}
}

void dfs(int num,int depth) {
	int temp[51][51];
	if (depth == K) {
		int Min = INT_MAX;
		//print_map();
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += A[i][j];
			}
			Min = min(Min, sum);
		}
		result = min(Min, result);
	}

	Copymap(temp, A);
	for (int i = 1; i <= K; i++) {
	
		if (visited[i] == 0) {
			//회전
			visited[i] = 1;
			//print_map();
			move_array(rotate_info[i].row, rotate_info[i].col, rotate_info[i].size);
			//print_map();
			dfs(i,depth+1);
			visited[i] = 0;
			Copymap(A, temp);
		}
	}

}



int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=M; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 1; i <=K; i++) {
		scanf("%d %d %d", &rotate_info[i].row, &rotate_info[i].col, &rotate_info[i].size);
	}
	for (int j = 1; j <= K; j++) {
		visited[j] = 0;
	}
	int temp[51][51];
	//print_map();
	for (int i = 1; i <= K; i++) {
		Copymap(temp, A);
		visited[i] = 1;
		//print_map();
		move_array(rotate_info[i].row, rotate_info[i].col, rotate_info[i].size);
		//print_map();
		dfs(i,1);
		visited[i] = 0;
		Copymap(A, temp);
	}
	printf("%d", result);

}
