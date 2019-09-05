#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countBits(int n) {
	int ret = 0;
	while (n) {
		if (n & 1) {
			ret++;
			n = n >> 1;//오른쪽으로 밀어 비트를 하나씩 없앰
		}
	}
	return ret;
}

bool cmp(int a, int b) {
	int x = countBits(a), y = countBits(b);
	return x > y;
}

bool check(vector<vector<string>> relation, int rowsize, int colsize, int subset) {
	for (int a = 0; a < rowsize - 1; a++) {
		for (int b = a + 1; b < rowsize; b++) {
			bool isSame = true;
			for (int k = 0; k < colsize; k++) {
				if ((subset & 1 << k) == 0) continue;
				if (relation[a][k] != relation[b][k]) {//같지않으면 false
					isSame = false;
					break;
				}
			}
			if (isSame) {//하나도 다른게 없을때 ->유일성을 만족하지 못함
				return false;
			}
		}
	}
	//2중포문 다돌면 유일성 만족함
	return true;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	vector<int> candidates;

	for (int i = 1; i < (1 << relation[0].size()); i++) {
		if (check(relation, relation.size(), relation[0].size(), i)) {
			candidates.push_back(i);
		}
	}
	sort(candidates.begin(), candidates.end(), cmp);

	while (!candidates.empty()) {//candidates 에있는건 유일성을 만족하는 것들
		int n = candidates.back();//마지막에꺼를 꺼냄 가장 작은거

		candidates.pop_back();
		answer++;
		for (vector<int>::iterator it = candidates.begin(); it != candidates.end();) {
			if ((n & *it) == n)
				it = candidates.erase(it);
			else
				it++;
		}
	}

	return answer;
}

int main() {
	vector<vector<string>> input = { {"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };
	printf("%d\n", solution(input));
}