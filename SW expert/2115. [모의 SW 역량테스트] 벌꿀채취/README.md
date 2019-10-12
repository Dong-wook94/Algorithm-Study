# 2115. [모의 SW 역량테스트] 벌꿀채취

> dfs 를 이용한  모든경우 생성, dfs를 이용한 최댓값 탐색

dfs를 여러번 이용하여 풀이하였다.

연속된 벌꿀통을 선택하는 과정에서도 dfs 선택된 연속된 벌꿀통에서 최댓값을 구하는 과정도 dfs를 이용하였다.

아래는 연속된 벌꿀통을 선택하는 과정 2개의 연속된 벌꿀통을 선택했을때 최댓값을 구하도록 하였다.

~~~c++
void dfs(vector<vector<int>> bucket) {
	if (bucket.size() == 2) {//종료조건
		for (int i = 0; i < bucket.size(); i++) {
			max_profit[i] = 0;
			MaxProfit(bucket[i], 0, 0, 0, i);
		}
		result = max(result, max_profit[0] + max_profit[1]);
		return;
	}
	for (int i = 0; i < map_size; i++) {
		for (int j = 0; j <= map_size - select_size; j++) {
			if (check_get_possible(i,j)) {
				vector<int> temp;
				for (int k = 0; k < select_size; k++) {
					visited[i][j + k] = 1;
					temp.push_back(map[i][j + k]);
				}
				bucket.push_back(temp);
				dfs(bucket);
				bucket.pop_back();
				for (int k = 0; k < select_size; k++) {
					visited[i][j + k] = 0;
				}
			}
		}
	}
}
~~~

아래는 최댓값을 구하는 dfs

~~~c++
void MaxProfit(vector<int> honey,int index,int check_sum,int profit,int order) {
	max_profit[order] = max(max_profit[order], profit);
	if (index >= select_size) {
		
		return;
	}
	if (check_sum + honey[index] <= max_volume) {
		MaxProfit(honey, index + 1, check_sum + honey[index], profit + pow(honey[index], 2), order);
		MaxProfit(honey, index + 1, check_sum, profit, order);
	}
}
~~~

