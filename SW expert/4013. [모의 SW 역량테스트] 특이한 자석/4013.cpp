#include<stdio.h>

typedef struct Magnet{
	int tooth[8];
	int dir;
}Magnet;

int n_rotate;

Magnet magnet[4];
int totalscore;
void Rotate(int index, int clockwise) {
	magnet[index].dir = clockwise;
	for (int i = index; i < 3; i++) {
		if (magnet[i].tooth[2] != magnet[i + 1].tooth[6]) {//´Ù¸¥±ØÀÏ¶§
			magnet[i + 1].dir = (-1)*magnet[i].dir;
		}
		else
			break;
	}
	for (int i = index; i > 0; i--) {
		if (magnet[i].tooth[6] != magnet[i - 1].tooth[2]) {
			magnet[i - 1].dir = (-1)*magnet[i].dir;
		}
		else
			break;
	}
	for (int i = 0; i < 4; i++) {
		if (magnet[i].dir == 1) {
			int temp = magnet[i].tooth[7];
			for (int j = 6; j >= 0; j--) {
				magnet[i].tooth[j + 1] = magnet[i].tooth[j];
			}
			magnet[i].tooth[0] = temp;
		}
		else if (magnet[i].dir == -1) {
			int temp = magnet[i].tooth[0];
			for (int j = 0; j <= 6; j++) {
				magnet[i].tooth[j] = magnet[i].tooth[j + 1];
			}
			magnet[i].tooth[7] = temp;
		}
	}
}

void Testcase() {
	scanf("%d", &n_rotate);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%d", &magnet[i].tooth[j]);
		}
	}
	for (int i = 0; i < n_rotate; i++) {
		for(int d = 0; d < 4; d++) {
			magnet[d].dir = 0;
		}
		int index, clockwise;
		scanf("%d %d", &index, &clockwise);
		Rotate(index-1,clockwise);
	}
	totalscore = 0;
	int score = 1;
	for (int i = 0; i < 4; i++) {
		if (magnet[i].tooth[0] == 1) {
			totalscore += score;
		}
		score *= 2;
	}
}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		Testcase();
		printf("#%d %d\n", i, totalscore);
	}
}