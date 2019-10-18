#include <stdio.h>
#include <algorithm>

using namespace std;

int D, W, K;//두께, 가로길이, 함격기준


int result;
int min_cnt;
int visited[15];
int film[14][21];
//약품을 투여하는 모든경우를 고려한다 -> 
bool check() {
	for (int i = 0; i < W; i++) {
		bool flag1 = false;//col별 체크
		for (int j = 0; j <= D - K; j++) {
			int cnt = 0;
			for (int p = j; p < j + K; p++) {//합격기준 개수만큼 같은지
				if (film[j][i] != film[p][i]) {//3개 체크하다가 다르면
					break;
				}
				cnt++;
			}
			if (cnt==K) {//3개가 같을때
				flag1 = true;
				break;
			}
		}
		if (!flag1)//col 통과
			return false;
	}
	return true;
}

void dfs(int row,int cnt) {
	int temp[21];
	if (cnt >= result)
		return;
	if (cnt >K || row >D) {
		return;
	}
	if (check()) {//종료조건
		result = min(result, cnt);
		return;
	}


	for (int i = 0; i < W; i++) {//원본복사해놓기
		temp[i] = film[row][i];
	}
	for (int c = 0; c < W; c++) {
		film[row][c] = 0;
	}
	dfs(row + 1, cnt + 1);
	for (int c = 0; c < W; c++) {
		film[row][c] = 1;
	}
	dfs(row + 1, cnt + 1);

	for (int i = 0; i < W; i++) {//되돌리기
		film[row][i] = temp[i];
	}
	dfs(row + 1,cnt);


}

void Testcase() {

	scanf("%d %d %d", &D, &W, &K);
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &film[i][j]);
		}
	}

	for (int i = 0; i < D; i++)
		visited[i] = 0;
	dfs(0,0);


}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		result = 15;
		Testcase();
		printf("#%d %d\n", i, result);
	}
}