#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
#define U 0
#define D 1
#define L 2
#define R 3
using namespace std;
class Pos {
public:
	int row;
	int col;
	Pos(){}
	Pos(int r, int c) {
		row = r;
		col = c;
	}
	bool operator<(const Pos & i) const {
		return row < i.row;
	}
};
vector<Pos> worm_hole[5];
int map_size;
int Map[102][102];
int result = 0;

int block[5][4] = {
	{D,R,U,L},{R,U,D,L},{L,U,R,D},{D,L,R,U},{D,U,R,L}
};
int dir_row[4] = {-1,1,0,0};//»óÇÏÁÂ¿ì
int dir_col[4] = {0,0,-1,1};

int Game(int row, int col, int dir) {
	int start_row = row;
	int start_col = col;
	int cnt = 0;
	while (1) {
		int next_row = row + dir_row[dir];
		int next_col = col + dir_col[dir];
		if (next_row<=0||next_col<=0||next_row>map_size||next_col>map_size) {//º®¿¡ ºÎµúÈú¶§
			dir = block[4][dir];
			row = next_row;
			col = next_col;
			cnt++;
			
		}
		else if (Map[next_row][next_col] == -1||(next_row==start_row&&next_col ==start_col)) {//ºí·¢È¦
			return cnt;
		}
		else if (Map[next_row][next_col]>=1&& Map[next_row][next_col]<=5) {//ºí·Ï
			dir = block[Map[next_row][next_col] - 1][dir]; //¹æÇâÀü
			row = next_row;
			col = next_col;
			cnt++;
		}
		else if (Map[next_row][next_col] >= 6 && Map[next_row][next_col] <= 10) {//¿úÈ¦
			//Pos next = worm_hole[Pos(next_row, next_col)];
			if ((worm_hole[Map[next_row][next_col] - 6][0].row == next_row) && (worm_hole[Map[next_row][next_col] - 6][0].col == next_col)) {
				row = worm_hole[Map[next_row][next_col] - 6][1].row;
				col = worm_hole[Map[next_row][next_col] - 6][1].col;
			}
			else {
				row= worm_hole[Map[next_row][next_col] - 6][0].row;
				col = worm_hole[Map[next_row][next_col] - 6][0].col;
			}
		}
		else {//°ø¹é
			row = next_row;
			col = next_col;
		}
		
	}
}

void BruteForce() {
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			if (Map[i][j] == 0) {//ºí·Ï, ¿úÈ¦, ºí·¢È¦ÀÌ ¾Æ´Ñ°ø°£
				for (int d = 0; d < 4; d++) {//¸ðµç¹æÇâ
					result = max(result,Game(i, j, d));
				}
			}
		}
	}
}
void Testcase() {
	
	scanf("%d", &map_size);
	for (int i = 0; i < 5; i++) {
		worm_hole[i].clear();
	}
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j] >= 6 && Map[i][j] <= 10) {
				worm_hole[Map[i][j] - 6].push_back(Pos(i, j));
			}
		}
	}
	/*for (int i = 0; i < 5; i++) {
		worm_hole.insert(wh[i][0], wh[i][1]);
		worm_hole.insert(wh[i][1], wh[i][0]);
	}*/
	BruteForce();

	

}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d",&testcase);
	for (int i = 1; i <= testcase; i++) {
		result = 0;
		Testcase();
		printf("#%d %d\n", i, result);
	}
}