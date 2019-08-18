# [백준] 17143 낚시왕
> 삼성 역량테스트 기출문제, 시뮬레이션

## 풀이
1. 낚시왕이 오른쪽으로 한칸 이동
2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
3. 상어가 이동한다.

위와 같은 순으로 진행되며 같은칸에 상어가 있는경우 사이즈가 큰 상어가 살아남는다. 이경우를 위해 map을 vector로 만들어서 해당 공간이 empty인경우에는 그냥 넣어주고 아닌경우에는 크기비교후 작은 상어를 없애주었다. 

이동시에 문제를 발견하는 데 오래걸렸는데 해당 방향을 보고 이동을 해야하는데 이동 후 방향을 잡아서 가끔 인덱스를 벗어나는 일이 발생하여 런타임에러가 발생했었는데 
~~~c++
for (int s = 0; s < shark[i].speed; s++) {
			switch (shark[i].dir) {//끝지점 도달시 방향 수정
			case 1://위
			case 2://아래
				if (next_row == 1)
					shark[i].dir = 2;
				if (next_row == R)
					shark[i].dir = 1;
				break;
			case 3://오
			case 4://왼
				if (next_col == 1)
					shark[i].dir = 3;
				if (next_col == C)
					shark[i].dir = 4;
				break;
			}
            //이동
			next_row += dir_row[shark[i].dir];
			next_col += dir_col[shark[i].dir];
		}
~~~
위와같이 방향을 먼저 제대로 잡고 이동하니 문제가 해결되었다. 


