#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());

	int sum = 0;

	for (int i = 0; i < weight.size(); i++) {
		sum += weight[i];
		if (weight[i + 1] > sum+1) {
			return sum + 1;
		}
	}

	return sum+1;
}