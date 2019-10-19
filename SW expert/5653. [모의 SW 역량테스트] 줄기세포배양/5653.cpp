#include <stdio.h>
#include <vector>

using namespace std;
int col_size, row_size, limit_time;

typedef struct Cell {
	int index;
	int row;
	int col;
	int active_time;
	int inactive_time;
	int time;
	int life;
	Cell() {}
	Cell(int r, int c, int t, int idx) {
		row = r;
		col = c;
		index = idx;
		active_time = t;
		inactive_time = t;
		time = t;
		life = 1;
	}
}Cell;

int Map[700][700];
vector<Cell> cells;
int cell_idx = 0;
int dir_row[4] = { 1,0,-1,0 };
int dir_col[4] = { 0,-1,0,1 };
int cell_cnt;
void SpreadCell(Cell cur_cell) {
	for (int i = 0; i < 4; i++) {
		int next_row = cur_cell.row + dir_row[i];
		int next_col = cur_cell.col + dir_col[i];
		if (Map[next_row][next_col] == 0) {
			cells.push_back(Cell(next_row, next_col, cur_cell.time, cell_idx));
			Map[next_row][next_col] = cell_idx;
			cell_idx++;
			cell_cnt++;
		}
		else if (Map[next_row][next_col] != 0 && cells[Map[next_row][next_col]].inactive_time == cells[Map[next_row][next_col]].time) {
			if (cur_cell.time > cells[Map[next_row][next_col]].time) {//더큰게 확장하는중일때
				cells[Map[next_row][next_col]].time = cur_cell.time;
				cells[Map[next_row][next_col]].active_time = cur_cell.time;
				cells[Map[next_row][next_col]].inactive_time = cur_cell.time;
			}
		}
	}
}

void Process() {//1초동안
	for (int i = 0; i < cells.size(); i++) {
		if (cells[i].life == 1) {
			if (cells[i].inactive_time > 0) {//비활성
				cells[i].inactive_time--;
			}
			else if (cells[i].active_time > 0) {//활성
				//if (cells[i].active_time == cells[i].time) {//첫활성 ->번식
				//	//SpreadCell(cells[i]);
				//}
				cells[i].active_time--;
			}

		}
	}

	for (int i = 0; i < cells.size(); i++) {
		if (cells[i].life == 1) {
			if (cells[i].inactive_time == 0 && cells[i].active_time + 1 == cells[i].time) {
				SpreadCell(cells[i]);
			}
			if (cells[i].active_time <= 0) {
				cells[i].life = 0;//죽음처리
				cell_cnt--;
			}
		}
	}
}

void Testcase() {
	scanf("%d %d %d", &row_size, &col_size, &limit_time);
	cell_idx = 0;
	cell_cnt = 0;
	for (int i = 0; i < 700; i++) {
		for (int j = 0; j < 700; j++) {
			Map[i][j] = 0;
		}
	}
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {

			int input_time;
			scanf("%d", &input_time);
			if (input_time != 0) {
				Cell temp;
				cells.push_back(Cell(300 + i, 300 + j, input_time, cell_idx));
				Map[300 + i][300 + j] = cell_idx;
				cell_idx++;
				cell_cnt++;
			}
		}
	}
	for (int i = 0; i < limit_time; i++) {
		Process();
	}
	cells.clear();
}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		Testcase();
		printf("#%d %d\n", i, cell_cnt);
	}
}