#include <stdio.h>
#include <vector>
using namespace std;

typedef struct DP {
	int min_cnt;
	vector<int> path;
	DP() { min_cnt = 0; }
}DP;

int N;

vector<DP> dp;
int main() {
	scanf("%d", &N);
	dp.assign(N + 1, DP());
	dp[1].min_cnt = 0;
	dp[1].path.push_back(1);
	for (int i = 2; i <= N; i++) {
		//i+1
		dp[i].min_cnt = dp[i - 1].min_cnt + 1;
		dp[i].path = dp[i - 1].path;
		dp[i].path.push_back(i);

		if (i % 3 == 0 && dp[i/3].min_cnt+1<dp[i].min_cnt) {
			dp[i].min_cnt = dp[i / 3].min_cnt + 1;
			dp[i].path = dp[i / 3].path;
			dp[i].path.push_back(i);
		}
		if (i % 2 == 0 && dp[i / 2].min_cnt + 1 < dp[i].min_cnt) {
			dp[i].min_cnt = dp[i / 2].min_cnt + 1;
			dp[i].path = dp[i / 2].path;
			dp[i].path.push_back(i);
		}
	}
	printf("%d\n", dp[N].min_cnt);
	for (int i = dp[N].path.size() - 1; i >= 0; i--) {
		printf("%d ", dp[N].path[i]);
	}
	printf("\n");
	return 0;
}