#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

int charge[4];
int plan[13];
int result;
void dfs(int month,int money) {
	if (month > 12) {//종료조건
		result = min(result, money);
		return;
	}
	if (month == 1) {
		dfs(month + 12, money + charge[3]);
	}
	if (month + 2 <= 12) {
		dfs(month + 3, money + charge[2]);
	}
	if (plan[month]>0) {
		int month_cost = plan[month] * charge[0];
		dfs(month + 1, money + month_cost);

		
		dfs(month + 1, money + charge[1]);
	}
	else {
		dfs(month + 1, money);
	}

}
void Testcase() {
	for (int i = 0; i < 4; i++) {
		scanf("%d", &charge[i]);
	}
	for (int i = 1; i <=12; i++) {
		scanf("%d", &plan[i]);
	}
	result = INT_MAX;
	dfs(1, 0);

}

int main() {
	int testcase;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		Testcase();
		printf("#%d %d\n", i, result);
	}
}
