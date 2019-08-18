#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Shark {
	int row;
	int col;
	int speed;
	int dir;
	int size;
	int life;
	int index;
	/*Shark(int r, int c, int s, int d, int z) {
		row = r;
		col = c;
		speed = s;
		dir = d;
		size = z;
	}*/
}Shark;

int R, C;
int n_shark;

vector<Shark> map[102][102];
vector<Shark> shark;

int dir_row[5] = {0,-1,1,0,0};
int dir_col[5] = {0,0,0,1,-1};
void Fishing(int pos);
void move_shark();
void map_clear();
int total_sum;
int main() {
	Shark temp;
	scanf("%d %d %d", &R, &C, &n_shark);
	temp.life = 1;
	for (int i = 0; i < n_shark; i++) {
		scanf("%d %d %d %d %d", &temp.row, &temp.col, &temp.speed, &temp.dir, &temp.size);
		temp.index = i;
		if (temp.dir < 3) {//상,하
			temp.speed = temp.speed%(R * 2 - 2);
		}
		else {
			temp.speed = temp.speed % (C * 2 - 2);
		}
		shark.push_back(temp);
		map[temp.row][temp.col].push_back(temp);
	}
	for (int i = 1; i <=C; i++) {
		Fishing(i);
		move_shark();
	}
	printf("%d\n", total_sum);
}

void Fishing(int pos) {
	for (int i = 1; i <= R; i++) {
		if (!map[i][pos].empty()) {
			total_sum += map[i][pos][0].size;//무게더하기
			map[i][pos][0].life = 0;//죽음처리
			shark[map[i][pos][0].index] = map[i][pos][0];//맵의 샤크정보 복사
			break;
		}
			

	}
	
}
void map_clear() {
	for (int i = 0; i < shark.size(); i++) {
		//printf("%d: (%d, %d) s :%d l :%d\n", shark[i].index, shark[i].row, shark[i].col, shark[i].size, shark[i].life);
		if(!map[shark[i].row][shark[i].col].empty())
			map[shark[i].row][shark[i].col].clear();
	}
	//printf("totalsum : %d\n",total_sum);
}
void move_shark() {
	map_clear();
	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].life == 0)//죽은거면 넘김
			continue;
		int next_row = shark[i].row;
		int next_col = shark[i].col;
		for (int s = 0; s < shark[i].speed; s++) {
			next_row += dir_row[shark[i].dir];
			next_col += dir_col[shark[i].dir];

			switch (shark[i].dir) {
			case 1://위
			case 2://아래
				if (next_row == 1)
					shark[i].dir = 2;
				if (next_row == R)
					shark[i].dir = 1;
				break;
			case 3://오
			case 4://왼
				if (next_col == 1)
					shark[i].dir = 3;
				if (next_col == C)
					shark[i].dir = 4;
				break;
			}
		}
		shark[i].row = next_row;
		shark[i].col = next_col;
		if(map[shark[i].row][shark[i].col].empty())
			map[shark[i].row][shark[i].col].push_back(shark[i]);
		else {
			if (map[shark[i].row][shark[i].col][0].size < shark[i].size) { //새로운게 더클때
				shark[map[shark[i].row][shark[i].col][0].index].life = 0;
				map[shark[i].row][shark[i].col][0] = shark[i];
			}
			else {
				shark[i].life = 0;
			}
		}
		
	}
	
}
//bool cmp(const Shark &s1, const Shark &s2) {
//	return s1.size > s2.size;
//}

