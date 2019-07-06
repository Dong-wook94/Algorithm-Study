#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Ball {
	int color;
	int size;
	int sum;
	int num;
}Ball;

Ball ball[200001];
int color_cnt[200001];

int N;//공개수
void CalculateSum();
bool cmp_size(const Ball &b1, const Ball &b2);
bool cmp_num(const Ball &b1, const Ball &b2);
void PrintResult();
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &ball[i].color, &ball[i].size);
		ball[i].sum = 0;
		ball[i].num = i;
	}
	sort(ball, ball + N,cmp_size);
	CalculateSum();
	sort(ball, ball + N, cmp_num);
	PrintResult();
}
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
			//ball[i].sum = sum - color_cnt[ball[i].color];
			same_color.push_back(ball[i]);
		}
	}
}

void PrintResult() {
	for (int i = 0; i < N; i++) {
		printf("%d\n", ball[i].sum);
	}
}
bool cmp_size(const Ball &b1, const Ball &b2) { //size 소팅
	return b1.size < b2.size;
}

bool cmp_num(const Ball &b1, const Ball &b2) { 
	return b1.num < b2.num;
}