# 백준 10800 컬러볼

[문제링크](https://www.acmicpc.net/problem/10800)

## 아이디어

간단하게 생각하여 O(n2)으로 문제를 풀게되면 시간초과가 난다.
그래서 O(nlogn)으로 문제를 해결하였다. 

각 볼은 자신과 보다 작은사이즈와 다른 색을 가진 볼들만 먹을수 있다.
그래서 사이즈별로 정렬후 계속 합해가며 같은색은 빼버리는 방법을 택하였다.

* 먼저 size 순으로 sorting한다.
* 소팅된 ball들의 합을 계속 구해나가는데 각 색들의 합을 저장할 배열과 누적합을 저장하고 변수에 계속 더해간다.
* 같은사이즈가 반복하여 나올경우 벡터에 저장하여 다음 볼과 사이즈가 다를경우에 한번에 합해준다.(이유는 이렇게안하면 같은사이즈지만 뒤에있는 볼은 더한값을 가지게 된다.)

~~~c++
void CalculateSum() {
	int sum;
	vector<Ball> same_color;
	ball[N].size = 2001;
	sum = 0;//누적되는합
	for (int i = 0; i < N;i++) {
		ball[i].sum = sum - color_cnt[ball[i].color];
		if (ball[i].size<ball[i+1].size) {//다음번에 사이즈가 커질때
			
			for (int j = 0; j < same_color.size(); j++) {
				sum += same_color[j].size;//누적합 더하고 
				color_cnt[same_color[j].color] += same_color[j].size;
			}
			sum += ball[i].size;
			color_cnt[ball[i].color] += ball[i].size;
			same_color.clear();
		}
		else {//사이즈 그대로
			same_color.push_back(ball[i]);
		}
	}
}
~~~
