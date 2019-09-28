#include <string>
#include <vector>
#include <algorithm>
//#include <iostream>
using namespace std;
int cnt = 0;
void dfs(int index, int sum, vector<int> numbers, int target) {
	if (index == numbers.size()) {
		if (sum == target)
			cnt++;
		return;
	}

	dfs(index + 1, sum + numbers[index], numbers, target);
	dfs(index + 1, sum - numbers[index], numbers, target);
}

int solution(vector<int> numbers, int target) {
	dfs(0, 0, numbers, target);
	return cnt;
}