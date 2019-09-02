#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef struct Time {
	int hour;
	int min;
	int time;
	Time(){}
	Time(string h, string m) {

		hour = stoi(h);
		min = stoi(m);
		time = hour * 60 + min;
	}
}Time;
typedef struct Bus{
	int time;
	vector<Time> crews;
}Bus;

vector<Bus> bus;

bool cmp(const Time t1, const Time t2) {
	return t1.time < t2.time;
}
string getTime(int t) {
	int hour = t / 60;
	int min = t % 60;
	string h, m;
	if (hour < 10)
		h = "0" + to_string(hour);
	else
		h = to_string(hour);
	if (min < 10)
		m = "0" + to_string(min);
	else
		m = to_string(min);

	return h + ":" + m;
}
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	vector<Time> crew;
	
	for (int i = 0; i < timetable.size(); i++) {
		crew.push_back(Time(timetable[i].substr(0, 2), timetable[i].substr(3, 2)));
	}
	sort(crew.begin(), crew.end(), cmp);//오름차순으로 정렬
	
	int btime = 540;
	for (int i = 0; i < n; i++) {
		Bus temp;
		temp.time = btime;
		bus.push_back(temp);
		btime = btime + t;
	}

	for (int i = 0; i < crew.size(); i++) {
		for (int j = 0; j < bus.size(); j++) {
			if (crew[i].time <= bus[j].time && bus[j].crews.size() < m) {//탑승가능 (버스시간보다 일찍왔고 버스에 자리가있는경우
				bus[j].crews.push_back(crew[i]);
			}
		}
	}

	if(bus[bus.size()-1].crews.size()<m){//막차탑승가능
		answer = getTime(bus[bus.size() - 1].time);
	}
	else {
		answer = getTime(bus[bus.size() - 1].time - 1);
	}


	return answer;
}
