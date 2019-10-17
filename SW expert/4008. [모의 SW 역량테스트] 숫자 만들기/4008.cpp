#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
vector<int> oper;
vector<int> operand;
int min_result;
int max_result;
void Combination() {
	sort(oper.begin(), oper.end());
	do {
		int result = operand[0];
		for (int i = 0; i < oper.size(); i++) {
			switch (oper[i]) {
			case 0:
				result += operand[i + 1];
				break;
			case 1:
				result -= operand[i + 1];
				break;
			case 2:
				result *= operand[i + 1];
				break;
			case 3:
				result /= operand[i + 1];
				break;
			}
		}
		min_result = min(min_result, result);
		max_result = max(max_result, result);
	} while (next_permutation(oper.begin(), oper.end()));
}
void Testcase() {
	scanf("%d", &N);
	int num_oper;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &num_oper);
		for (int j = 0; j < num_oper; j++) {
			oper.push_back(i);
		}
	}
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		operand.push_back(input);
	}
	Combination();
	oper.clear();
	operand.clear();
}

int main() {
	//freopen("Text.txt", "r", stdin);
	int testcase;
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		max_result = INT_MIN;
		min_result = INT_MAX;
		Testcase();
		printf("#%d %d\n", i, max_result - min_result);
	}
}