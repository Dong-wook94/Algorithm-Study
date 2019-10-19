# 5656. [모의 SW 역량테스트] 벽돌 깨기

> 매우 과정이 긴 시뮬레이션 dfs+bfs 모두 이용하였다.

1. 떨어뜨릴 위치 정하기
2. 블록 삭제
3. 블록 정렬

여기서 떨어뜨릴 위치는 dfs로 블록 삭제는 bfs로 진행하였다.

문제푸는 과정에서 오류가 생겼는데

테스트 케이스중 10개나 틀려 찾는데 고생하였다.

틀린코드

~~~c++
void DownBlock() {
	for (int j = 0; j < W; j++) {
		int level = H - 1;
		for (int i = H - 1; i > 0; i--) {
			if (Map[i][j] != 0) {
				int temp = Map[i][j];
				Map[i][j] = 0;
				Map[level][j] = temp;
				level--;
			}
		}
	}
}
~~~



정답코드

~~~c++
void DownBlock() {
	for (int j = 0; j < W; j++) {
		//int level = H - 1;
		for (int i = H - 1; i > 0; i--) {
			for (int k = i - 1; k >= 0; k--) {
				if (Map[i][j] != 0)break;
				if (Map[k][j] != 0) {
					Map[i][j] = Map[k][j];
					Map[k][j] = 0;
					break;
				}
			}
		}
	}
}
~~~

