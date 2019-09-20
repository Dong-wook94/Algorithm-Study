#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

deque<int> dq;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	for (int i = 0; i < operations.size(); i++) {
		int val = atoi(operations[i].substr(2).c_str());
		if (operations[i].substr(0, 1) == "I") {
			dq.push_back(val);
		}
		else {
			sort(dq.begin(), dq.end(),greater<int>());
			if (dq.empty())//비었을땐 무시
				continue;
			if (val == -1) {
				dq.pop_back();
			}
			else {
				dq.pop_front();
			}

		}
		for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++) {
			cout << *iter<<" ";
		}
		cout << endl;
	}
	
	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
		return answer;
	}
	sort(dq.begin(), dq.end());
	answer.push_back(*dq.begin());
	answer.push_back(*(dq.end()-1));

	return answer;
}

int main() {
	vector<int> sol = solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });

}