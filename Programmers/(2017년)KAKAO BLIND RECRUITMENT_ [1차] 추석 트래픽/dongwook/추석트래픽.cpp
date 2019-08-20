#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Time {

	int start;
	int end;
	Time() {

	}
	Time(string hour, string min, string sec, string m_sec, string p_time) {
		int hh = stoi(hour) * 60 * 60 * 1000;
		int mm = stoi(min) * 60 * 1000;
		int ss = stoi(sec) * 1000;
		int ms = stoi(m_sec);
		int pt = (int)(stod(p_time)*1000);
		end = hh + mm + ss + ms;
		start = end - pt+1;
	}
}Time;

//typedef struct Duration {
//	int time;
//	int start;
//	Duration(){}
//	Duration(int tt, int st) {
//		time = tt;
//		start = st;
//	}
//}Duration;

//struct cmp_start {
//	bool operator()(Time t1,Time t2) {
//		return t1.start > t2.start;
//	}
//};
//struct cmp_end {
//	bool operator()(Time t1, Time t2) {
//		return t1.end > t2.end;
//	}
//};

vector<Time> t_data;
//priority_queue<Time, vector<Time>, cmp_start> start_pq;
//priority_queue<Time, vector<Time>, cmp_end> end_pq;
bool cmp(const Time &t1, const Time &t2);
int solution(vector<string> lines);
int main() {
	vector<string> ex1 = { "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" };

	printf("%d\n", solution(ex1));
}
int solution(vector<string> lines) {
	int cnt = 0,max_cnt =0;
	string hour, min, sec, m_sec, p_time;
	for (int i = 0; i < lines.size(); i++) {
		hour.assign(lines[i], 11, 2);
		min.assign(lines[i], 14, 2);
		sec.assign(lines[i], 17, 2);
		m_sec.assign(lines[i], 20, 3);
		p_time = lines[i].substr(24);//24번째부터 끝까지 
		p_time.pop_back();//s빼기.
		t_data.push_back(Time(hour,min,sec,m_sec,p_time));
		//start_pq.push(t_data[i]);
		//end_pq.push(t_data[i]);
	}
	sort(t_data.begin(), t_data.end(), cmp);

	for (int i = 0; i < t_data.size(); i++) {
		cnt = 0;
		for (int j = 0; j < t_data.size(); j++) {
			if (t_data[i].start <= t_data[j].start&&t_data[i].start + 999 >= t_data[j].start)
				cnt++;
			else if (t_data[i].start > t_data[j].start && t_data[i].start<=t_data[j].end)
				cnt++;
			else if (t_data[i].start + 999 < t_data[j].start)
				break;
			if (max_cnt < cnt)
				max_cnt = cnt;
		}
	}
	for (int i = 0; i < t_data.size(); i++) {
		cnt = 0;
		for (int j = 0; j < t_data.size(); j++) {
			if (t_data[i].start-999>t_data[j].end)
				break;
			else if (t_data[i].start-999<=t_data[j].end && t_data[i].start>=t_data[j].start)
				cnt++;
			else if (t_data[i].start - 999 <=t_data[j].start && t_data[i].start >= t_data[j].start)
				cnt++;
			if (max_cnt < cnt)
				max_cnt = cnt;
		}
	}
	return max_cnt;

}
bool cmp(const Time &t1, const Time &t2) {
	return t1.start < t2.start;
}
