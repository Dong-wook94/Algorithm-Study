#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
typedef struct Pos {
	int row;
	int col;
	int time;
	Pos(){}
	Pos(int r, int c, int t) {
		row = r;
		col = c;
		time = t;
	}
}Pos;


using namespace std;

queue<Pos> q;
int rowsize, colsize,manhole_row,manhole_col, escape_time;
int map[51][51];
int visited[51][51];
int dir_row[4] = {1,0,-1,0};//하,좌,상,우
int dir_col[4] = {0,-1,0,1};

void bfs() {
	visited[manhole_row][manhole_col] = 1;
	q.push(Pos(manhole_row, manhole_col,1));

	while (!q.empty()) {
		Pos pos=q.front();
		q.pop();
		//if (pos.time > escape_time)
			//continue;
		for (int i = 0; i < 4; i++) {
			int next_row = pos.row + dir_row[i];
			int next_col = pos.col + dir_col[i];
			if (next_row < 0 || next_col < 0 || next_row >= rowsize || next_col >= colsize)
				continue;
			if (visited[next_row][next_col] != 0)
				continue;
			if (pos.time >= escape_time)
				continue;
			if (map[pos.row][pos.col] == 2) {
				if (i == 1 || i == 3)
					continue;
			}
			else if (map[pos.row][pos.col] == 3) {
				if (i == 0 || i == 2)
					continue;
			}
			else if (map[pos.row][pos.col] == 4) {
				if (i == 0 || i == 1)
					continue;
			}
			else if (map[pos.row][pos.col] == 5) {
				if (i == 1 || i == 2)
					continue;
			}
			else if (map[pos.row][pos.col] == 6) {
				if (i == 2 || i == 3)
					continue;
			}
			else if (map[pos.row][pos.col] == 7) {
				if (i == 0 || i == 3)
					continue;
			}
			
			if (i == 0) {
				if (map[next_row][next_col] == 1 || map[next_row][next_col] == 2 || map[next_row][next_col] == 4 || map[next_row][next_col] == 7) {
					visited[next_row][next_col] = pos.time + 1;
					
					q.push(Pos(next_row, next_col, pos.time + 1));
				}
			}
			else if (i == 1) {
				if (map[next_row][next_col] == 1 || map[next_row][next_col] == 3 || map[next_row][next_col] == 4 || map[next_row][next_col] == 5) {
					visited[next_row][next_col] = pos.time + 1;
					
					q.push(Pos(next_row, next_col, pos.time + 1));
				}
			}
			else if (i == 2) {
				if (map[next_row][next_col] == 1 || map[next_row][next_col] == 2 || map[next_row][next_col] == 5 || map[next_row][next_col] == 6) {
					visited[next_row][next_col] = pos.time + 1;
					
					q.push(Pos(next_row, next_col, pos.time + 1));
				}
			}
			else if (i == 3) {
				if (map[next_row][next_col] == 1 || map[next_row][next_col] == 3 || map[next_row][next_col] == 6 || map[next_row][next_col] == 7) {
					visited[next_row][next_col] = pos.time + 1;
					
					q.push(Pos(next_row, next_col, pos.time + 1));
				}
			}
			
		}
		
	}
}


int Testcase() {
	scanf("%d %d %d %d %d", &rowsize, &colsize, &manhole_row, &manhole_col, &escape_time);
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			scanf("%d", &map[i][j]);
			visited[i][j] = 0;
		}
	}
	bfs();
	int cnt = 0;
	//printf("map 결과 : \n");
	for (int i = 0; i < rowsize; i++) {
		for (int j = 0; j < colsize; j++) {
			//printf("%d ",visited[i][j]);
			if (visited[i][j]!=0)
				cnt++;
		}
		//printf("\n");
	}
	return cnt;
}

int main() {
	int testcase;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		printf("#%d %d\n",i,Testcase());
	}
}