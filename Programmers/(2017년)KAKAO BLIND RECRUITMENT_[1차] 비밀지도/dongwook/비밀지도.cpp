
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	for (int i = 0; i < n; i++) {
		string line = "";
		int num = arr1[i] | arr2[i];

		for (int j = 0; j < n; j++) {

			if (num % 2 == 1)
				line += "#";
			else
				line += " ";
			num = num / 2;
		}
		reverse(line.begin(), line.end());
		answer.push_back(line);
	}
	return answer;

}

