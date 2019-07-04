#include	<stdio.h>
#include	<stdlib.h>

int solution(int a, int b) {
	int ans = 0, i;
	int small_num, large_num;	// for number
	int small_lev, large_lev;	// for level
	int small_sum = 0, large_sum = 0;

	// check small, large number
	if (a <= b) {
		small_num = a;
		large_num = b;
	}
	else {
		small_num = b;
		large_num = a;
	}

	// check small, large number level
	for (i = 1; i < 200; i++) {
		if (i*(i + 1) / 2 >= small_num) {
			small_lev = i;
			break;
		}
	}
	for (i = i; i < 200; i++) {
		if (i*(i + 1) / 2 >= large_num) {
			large_lev = i;
			break;
		}
	}

	if (small_lev == large_lev)
		ans = large_num - small_num;
	else {
		// 왼쪽 최대 이동
		for (i = small_lev; i < large_lev; i++) {
			small_sum += i;
		}
		small_sum += small_num;

		// 오른쪽 최대 이동
		for (i = small_lev + 1; i <= large_lev; i++) {
			large_sum += i;
		}
		large_sum += small_num;

		if (large_num >= small_sum && large_num <= large_sum) {
			ans = large_lev - small_lev;
		}
		else if (large_num < small_sum) {
			ans = small_sum - large_num + large_lev - small_lev;
		}
		else {
			ans = large_num - large_sum + large_lev - small_lev;
		}
	}

	return ans;
}

int main(void) {
	int c = 0, i;
	int a = 0;
	int b = 0;

	scanf("%d", &c);
	for (i = 0; i < c; i++) {
		scanf("%d %d", &a, &b);
		printf("#%d %d\n", i + 1, solution(a, b));
	}
}