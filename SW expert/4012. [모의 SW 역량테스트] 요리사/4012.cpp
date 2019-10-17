#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;
int N;
int synergy[17][17];
vector<int> Select;
int result;

void Combination() {
	Select.clear();
	for (int i = 0; i < N / 2; i++) {
		Select.push_back(0);
		Select.push_back(1);
	}
	sort(Select.begin(), Select.end());
	do {
		int sumA = 0;
		int sumB = 0;
		for (int i = 0; i < Select.size(); i++) {
			for (int j = 0; j < Select.size(); j++) {
				if (Select[i] == 0 && Select[j] == 0) {
					sumA += synergy[i+1][j+1];
				}
				else if (Select[i] == 1 && Select[j] == 1) {
					sumB += synergy[i+1][j+1];
				}
			}
		}
		result = min(result, abs(sumA - sumB));
	} while (next_permutation(Select.begin(), Select.end()));
}

void Testcase() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &synergy[i][j]);
		}
	}
	Combination();


}

int main() {
	int testcase;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		result = INT_MAX;
		Testcase();
		printf("#%d %d\n", i, result);
	}
}