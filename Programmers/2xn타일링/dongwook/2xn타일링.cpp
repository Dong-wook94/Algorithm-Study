#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> Select;
int combination(int num_vertical, int num_hor);
int solution(int n) {
	int answer = 0;

	int dp[60001];

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	answer = dp[n];
	return answer;
}


int main() {
	printf("%d", solution(4));
}