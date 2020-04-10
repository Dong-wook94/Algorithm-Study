#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	sort(routes.begin(), routes.end());
	
	int camera_pos = routes[0][1];
	for (int i = 0; i < routes.size()-1; i++) {
		if (camera_pos > routes[i][1]) camera_pos = routes[i][1];

		if (camera_pos < routes[i + 1][0]) {
			answer += 1;
			camera_pos = routes[i + 1][1];
		}
	}

	return answer;
}

int main() {

	cout << solution({ {-20,15}, {-14,-5}, {-18,-13}, {-5,-3} }) << endl;

}