#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Job {
private:
public:
	int start_time;
	int work_time;
	Job(){}
	Job(int start_time, int work_time) {
		this->start_time = start_time;
		this->work_time = work_time;
	}
	bool operator>(const Job& j) const {
		if (work_time == j.work_time) return start_time > j.start_time;
		return work_time > j.work_time;
	}
	
};


priority_queue<Job,vector<Job>,greater<Job>> pq;

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	for (int i = 0; i < jobs.size(); i++) {
		pq.push(Job(jobs[i][0], jobs[i][1]));
	}

	vector<Job> List;
	while (!pq.empty()) {
		List.push_back(pq.top());
		pq.pop();
	}
	int time = 0;
	int total_time = 0;

	while (!List.empty()) {
		for (int i = 0; i < List.size(); i++) {
			if (time >= List[i].start_time) {
				time += List[i].work_time;
				total_time += time - List[i].start_time;
				List.erase(List.begin() + i);
				break;
			}
			if (i == List.size() - 1)
				time++;
		}
		
		
	}
	answer = total_time / jobs.size();
	return answer;
}

int main() {
	printf("%d", solution({ {0,3},{1,9},{500,6} }));
}

