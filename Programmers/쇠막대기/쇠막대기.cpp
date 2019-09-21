#include <string>
#include <vector>

using namespace std;

typedef struct Stick {
	int cnt_laser;
	Stick() {}
	Stick(int c) {
		cnt_laser = c;
	}
}Stick;

vector<Stick> sticks;
int solution(string arrangement) {
	int answer = 0;

	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement.substr(i, 2) == "()") {//레이저인경우
			for (int i = 0; i < sticks.size(); i++) {
				sticks[i].cnt_laser++;
			}
			i++;
		}
		else if (arrangement[i] == '(') {//스틱시작
			sticks.push_back(Stick(0));
		}
		else {

			answer += (sticks[sticks.size()-1].cnt_laser + 1);
			sticks.erase(sticks.end()-1);
		}
	}
	return answer;
}

int main() {
	printf("%d", solution("()(((()())(())()))(())"));
}