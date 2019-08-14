#include <stdio.h>
#include <vector>
typedef struct AirCleaner {
	int row;
	int col;
	AirCleaner(int rr, int cc) {
		row = rr;
		col = cc;
	}
}AirCleaner;

using namespace std;

int R, C, T;
int Map[51][51];
int NextMap[51][51];
vector<AirCleaner> cleaner;
int dir_row[4] = {0,-1,0,1};
int dir_col[4] = {1,0,-1,0};// 오른 위 왼 아래 (반시계방향)
int circulate[2][4] = { 
	{ 0,1,2,3 },
{0,3,2,1} 
};
void init_NextMap();
void copyMap(int a[][51], int b[][51]);
void SpreadDust();
void OperAirCleaner(int num);
void count_dust();
int main() {
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == -1) {
				cleaner.push_back(AirCleaner(i, j));
			}
		}
	}
	

	for (int i = 0; i < T; i++) {
		SpreadDust();
		copyMap(NextMap, Map);
		OperAirCleaner(0);
		OperAirCleaner(1);
		copyMap(Map, NextMap);
	}
	count_dust();

}

void init_NextMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			NextMap[i][j] = 0;
		}
	}
	NextMap[cleaner[0].row][cleaner[0].col] = -1;
	NextMap[cleaner[1].row][cleaner[1].col] = -1;
}
void copyMap(int a[][51],int b[][51]) {
	//printf("\n");
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			a[i][j] = b[i][j];
			//printf("%d ", Map[i][j]);
		}
		//printf("\n");
	}

}
void SpreadDust() {
	int next_row;
	int next_col;
	int cnt;
	init_NextMap();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] >0) {
				cnt = 0;
				for (int k = 0; k < 4; k++) {
					next_row = i + dir_row[k];
					next_col = j + dir_col[k];
					if (next_row >= 0 && next_col >= 0 && next_row < R&&next_col < C&&Map[next_row][next_col]!=-1) {
						NextMap[next_row][next_col] += (Map[i][j] / 5);
						cnt++;
					}
				}
				NextMap[i][j] = NextMap[i][j] + Map[i][j] - ((Map[i][j] / 5)*cnt);
			}
		}
	}
	copyMap(Map, NextMap);
}
void OperAirCleaner(int num) {

	int col = cleaner[num].col+1;
	int row = cleaner[num].row;

	NextMap[row][col] = 0;

	for (int i = 0; i < 4; i++) {
		while (1) {
			int next_row = row + dir_row[circulate[num][i]];
			int next_col = col + dir_col[circulate[num][i]];

			if (!(next_row >= 0 && next_col >= 0 && next_row < R&&next_col < C&&Map[next_row][next_col] != -1)) {
				break;
			}
			NextMap[next_row][next_col] = Map[row][col];
			row = next_row;
			col = next_col;
		}
	}

}

void count_dust() {
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] > 0) {
				cnt += Map[i][j];
			}
		}
	}
	printf("%d\n", cnt);
}