#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Block {
	int row;
	int col;
	int power;
	Block(){}
	Block(int r, int c,int p) {
		row = r;
		col = c;
		power = p;
	}
}Block;

queue<Block> q;
int Map[16][13];
int N, W, H;

//벽돌을 떨어뜨린다. //완탐//dfs
//깨질때 처리 
//최댓값 찾기

int dir_row[4] = {1,0,-1,0};
int dir_col[4] = {0,-1,0,1};
int result;
void bfs() {
	while (!q.empty()) {
		Block cur = q.front();
		q.pop();
		Map[cur.row][cur.col] = 0;

		for (int d = 0; d < 4; d++) {
			for (int j = 1; j<cur.power; j++) {
				int next_row = cur.row + dir_row[d] * j;
				int next_col = cur.col + dir_col[d] * j;
				if (next_row < 0 || next_col < 0 || next_row >= H || next_col >= W)
					continue;
				if (Map[next_row][next_col] != 0) {
					q.push(Block(next_row, next_col, Map[next_row][next_col]));
					Map[next_row][next_col] = 0;
				}
			}
		}
	}
}
void DownBlock() {
	for (int j = 0; j < W; j++) {
		//int level = H - 1;
		for (int i = H - 1; i > 0; i--) {
			for (int k = i - 1; k >= 0; k--) {
				if (Map[i][j] != 0)break;
				if (Map[k][j] != 0) {
					Map[i][j] = Map[k][j];
					Map[k][j] = 0;
					break;
				}
			}
		}
	}
}
void BlockBreak(int idx) {

	for (int i = 0; i < H; i++) {
		if (Map[i][idx] != 0) {//벽돌을 만날때
			q.push(Block(i, idx, Map[i][idx]));
			bfs();
			DownBlock();
			break;
		}
	}
}
void Copymap(int a[][13],int b[][13]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			a[i][j] = b[i][j];
		}
	}


}


void dfs(int cnt) {
	if (cnt >=N) {
		int b_cnt=0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (Map[i][j] != 0) {
					b_cnt++;
				}
			}
		}
		result = min(result, b_cnt);
		return;
	}
	int temp[16][13];
	for (int i = 0; i < W; i++) {
		Copymap(temp,Map);
		BlockBreak(i);
		dfs(cnt + 1);
		Copymap(Map,temp);
	}
}

void Testcase() {
	scanf("%d %d %d", &N, &W, &H);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
		
			scanf("%d", &Map[i][j]);
		}
	}
	dfs(0);

}

int main() {
	int testcase;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		result = 12 * 15;
		Testcase();
		printf("#%d %d\n", i, result);
	}

}