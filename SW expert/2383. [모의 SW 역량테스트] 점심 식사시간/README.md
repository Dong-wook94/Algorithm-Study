# 2383. [모의 SW 역량테스트] 점심 식사시간

> dfs를 이용한 모든 경우 생성 후 최솟값 도출

아래의 코드는 모든 사람이 두계단을 선택하는 모든 경우의수를 생성하는 함수

~~~c++
void dfs(int idx) {
	if (idx == person.size()) {//경우의수 구했을때
		min_result = min(min_result, lunch() + 1);
		return;
	}
	for (int i = 0; i < 2; i++) {
		Select[idx] = i;
		dfs(idx + 1);
	}
}
~~~



위의 경우의수 생성을 바탕으로 가장늦게 계단을 탈출하는 시간을 반환하는 함수. 

~~~c++
int lunch() {
	for (int i = 0; i < person.size(); i++) {
		if (Select[i] == 0) {
			stair[0].wait.push_back(person[i]);
		}
		else {
			stair[1].wait.push_back(person[i]);
		}
	}
	sort(stair[0].wait.begin(), stair[0].wait.end(), cmp0);
	sort(stair[1].wait.begin(), stair[1].wait.end(), cmp1);
	int result = 0;
	for (int i = 0; i < 2; i++) {
		Person temp;
		int wait_time = 0;
		if (stair[i].wait.empty())
			continue;
		while (!stair[i].wait.empty()) {
			while (stair[i].stair_q.size() < 3) {
				if (stair[i].wait.empty()) {
					while (!stair[i].stair_q.empty())
						stair[i].stair_q.pop();
					break;
				}
				temp = stair[i].wait[stair[i].wait.size() - 1];
				stair[i].wait.pop_back();
				stair[i].stair_q.push(temp);
			}
			if (stair[i].wait.empty()) {
				while (!stair[i].stair_q.empty())
					stair[i].stair_q.pop();
				break;
			}
			if (stair[i].stair_q.front().dist[i] + stair[i].length < stair[i].wait[stair[i].wait.size() - 1].dist[i]) {
				stair[i].stair_q.pop();
			}
			else {
				stair[i].wait[stair[i].wait.size() - 1].dist[i] += (stair[i].stair_q.front().dist[i] + stair[i].length - stair[i].wait[stair[i].wait.size() - 1].dist[i]);//지연되는 시간만큼 더해줌 (가장빨리나가는 사람탈출시간 - 젤먼저 들어올 사람 계단도착시간)
				stair[i].stair_q.pop();
			}
		}
		result = max(result, temp.dist[i] + stair[i].length);
	}
	return result;
}
~~~

