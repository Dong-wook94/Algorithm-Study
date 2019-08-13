#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[101][10][1024];
void init_dp();
void cal_step();
int main() {
	
	scanf("%d", &N);
	init_dp();
	cal_step();

	
	
}
void init_dp() {
	for (int i = 1; i < 10; i++) {
		dp[0][i][1 << i]=1;
	}
}
void cal_step() {
	int total = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j == 0)
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % 1000000000;
				else if (j == 9)
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % 1000000000;
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % 1000000000;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % 1000000000;
				}
			}
			
		}
	}
	for (int i = 0; i < 10; i++) {
		total = (total + dp[N - 1][i][1023])%1000000000;
	}
	//total = total % 1000000000;
	printf("%d\n", total);
}