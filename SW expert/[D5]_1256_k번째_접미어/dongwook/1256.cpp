#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
void FindSubString(int t);
int idx;
char String[401];
vector<string> arr;

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		FindSubString(t);
	}
}

void FindSubString(int t) {
	string sub;
	scanf("%d", &idx);
	scanf("%s", String);
	arr.push_back(sub.assign(String));

	if (idx > arr[0].length()) {
		printf("#%d none\n", t);
		arr.clear();
		return;
	}
	for (int i = 1; i < arr[0].length(); i++) {
		sub = arr[0].substr(i, arr[0].length() - 1);
		arr.push_back(sub);
	}
	sort(arr.begin(), arr.end());
	strcpy(String, arr[idx - 1].c_str());
	printf("#%d %s\n", t, String);
	arr.clear();
}