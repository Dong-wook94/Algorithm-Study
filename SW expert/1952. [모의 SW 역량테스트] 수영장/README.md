# 1952. [모의 SW 역량테스트] 수영장
> dfs를 이용한 완전탐색

간단한문제다 1일 1달 3달 1년간 가능한경우를 모두 탐색한다.

~~~c++
void dfs(int month,int money) {
	if (month > 12) {//종료조건
		result = min(result, money);
		return;
	}
	if (month == 1) {//1월일때 연간회원권
		dfs(month + 12, money + charge[3]);
	}
	if (month + 2 <= 12) {//1월~10월을 시작으로 3달회원권 
		dfs(month + 3, money + charge[2]);
	}
	if (plan[month]>0) {//해당달에 요금이 있을때
        //1일이용권
		int month_cost = plan[month] * charge[0];
		dfs(month + 1, money + month_cost);
        
        //1달이용권
		dfs(month + 1, money + charge[1]);
	}
	else {//해당달에 요금이 없을때
		dfs(month + 1, money);
	}

}
~~~
