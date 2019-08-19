# [백준] 17142. 연구소
> 삼성 역량테스트 기출문제

## 풀이방법
1. 바이러스가 놓일수 있는 위치마다 BFS를 통해 최소시간을 탐색한다.
2. 바이러스가 놓일수 있는 경우는 algorithm 라이브러리의 next_permutation을 사용해 풀이하였다
~~~c++
void Select_Virus() {
	vector<int> select;
	int time=-1;
	int check = 0;
	for (int i = 0; i < n_acvirus; i++)
		select.push_back(1);
	for (int i = 0; i < (virus.size() - n_acvirus); i++)
		select.push_back(0);
	sort(select.begin(), select.end());

	do {
		for (int i = 0; i < map_size; i++) {//방문체크 위해초기화
			memset(visited[i], 0, sizeof(int)*map_size);
		}
		for (int i = 0; i < select.size(); i++) {
			if (select[i] == 1) {
				visited[virus[i].row][virus[i].col] = 1;
				q.push(virus[i]);
			}
		}
		time = Spread_Virus();
		check = check0();
		if (time < min_time&&check != 0) {
			min_time = time;
		}
	} while (next_permutation(select.begin(), select.end()));
}
~~~

3. 최소시간을 갱신할때 아래의 조건을 추가하여 확산시 비활성 바이러스를 활성바이러스로 바꾸는 경우는 확산 시간계산에서 제외하였다. 갱신에만 제외.
~~~c++
if (max_time < next.time&&map[next.row][next.col]==0)
						max_time = next.time;
~~~