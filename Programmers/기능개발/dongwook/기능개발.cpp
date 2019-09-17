#include <string>
#include <vector>

using namespace std;

typedef struct Func {
	int required_time;
	
	Func(int prog, int speed) {
		int remain = 100 - prog;
		if (remain % speed == 0) {
			required_time = remain / speed;
		}
		else {
			required_time = (remain / speed) + 1;
		}
	}
}Func;

vector<Func> functions;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	for (int i = 0; i < progresses.size(); i++) {
		functions.push_back(Func(progresses[i], speeds[i]));
	}

	int cur_time=functions[0].required_time;
	int cnt = 1;
	for (int i = 1; i < functions.size(); i++) {
		if (functions[i].required_time > cur_time) {
			answer.push_back(cnt);
			cnt = 1;
			cur_time = functions[i].required_time;
		}
		else {
			cnt++;
		}

	}
	answer.push_back(cnt);

	return answer;
}

int main() {
	vector<int> ex1 = solution({ 40, 93, 30, 55, 60, 65 }, { 60, 1, 30, 5 , 10, 7 });

	for(int i = 0; i < ex1.size(); i++) {
		printf("%d ",ex1[i]);
	}
}