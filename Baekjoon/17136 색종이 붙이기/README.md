# 색종이 붙이기
> dfs를 이용하여 완전탐색

첨에 잘못생각하여 크기가 큰 색종이부터 고려하는 그리디한방법으로 
탐색하였으나 문제가 있었다. 그래서 백트래킹을 이용하여 푸니 통과되었다.
~~~
void dfs(int index, int cnt){
	if (index==100) {
		min_result = min(min_result, cnt);
		return;
	}
	int row = index / 10;
	int col = index % 10;
	
	if (min_result <= cnt)
		return;

	if (map[row][col] == 1) {
		for (int i = 5; i > 0; i--) {
			if (paper_cnt[i] > 0) {
				if (Check_paper(row, col, i)) {
					fill(row, col, i, 0);
					paper_cnt[i]--;
					dfs(index + 1, cnt + 1);
					fill(row, col, i, 1);
					paper_cnt[i]++;
				}
			}
		}
	}
	else {
		dfs(index + 1, cnt);
	}
}
~~~

