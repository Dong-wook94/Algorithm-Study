#include <vector>

using namespace std;

vector<vector<int>> visited;
int cnt;
void dfs(int r, int c, int m, int n, int color, vector<vector<int>> picture);


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<int> answer(2);

	visited.assign(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && visited[i][j] == 0) {
				number_of_area++;
				cnt = 0;
				dfs(i, j, m, n, picture[i][j], picture);
				if (max_size_of_one_area < cnt)
					max_size_of_one_area = cnt;
			}
		}
	}


	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

void dfs(int r, int c, int m, int n, int color, vector<vector<int>> picture) {
	visited[r][c] = 1;
	cnt++;
	int dir_row[4] = { 1,0,-1,0 };
	int dir_col[4] = { 0,-1,0,1 };

	for (int i = 0; i < 4; i++) {
		int next_row = r + dir_row[i];
		int next_col = c + dir_col[i];
		if (!(next_row < m &&next_row >= 0 && next_col >= 0 && next_col < n))
			continue;
		if (visited[next_row][next_col] == 0 && picture[next_row][next_col] == color) {
			dfs(next_row, next_col, m, n, color, picture);
		}
	}
}

