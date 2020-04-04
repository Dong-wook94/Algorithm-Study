#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> counts;
int total_cnt = 0;
int solution(string name) {
	int result = 0;
	for (int i = 0; i < name.size(); i++) {
		int cnt = min(name[i] - 'A', 'Z' - name[i] + 1);
		counts.push_back(cnt);
		total_cnt += cnt;
	}
	int idx = 0;
	while (1) {
		
		result += counts[idx];
		cout << idx <<","<<result<< endl;
		total_cnt -= counts[idx];
		counts[idx] = 0;
		if (total_cnt == 0)
			break;
		int left_cnt = 0;
		int right_cnt = 0;
		int left_idx = idx;
		int right_idx = idx;
		int n = name.size();
		while (counts[left_idx] <= 0) {
			left_cnt++;
			left_idx--;
			left_idx = (left_idx < 0) ? n - 1 : left_idx;
		}
		while (counts[right_idx]<=0) {
			right_cnt++;
			right_idx = (right_idx + 1) % n;
		}
		if (left_cnt < right_cnt) {
			result += left_cnt;
			idx = left_idx;
		}
		else {
			result += right_cnt;
			idx = right_idx;
		}
	}
	return result;
}

int main() {
	cout << solution("BBAABB") << endl;
}