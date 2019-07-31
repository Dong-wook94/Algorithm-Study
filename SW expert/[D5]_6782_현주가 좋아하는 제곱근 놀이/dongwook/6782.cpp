#include <stdio.h>
#include <math.h>

int Test();

int main() {
	int testcase;

	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		printf("#%d %d\n", t, Test());
	}
}

int Test() {
	long long num,temp;
	int cnt = 0;
	scanf("%lld", &num);

	while (num!=2) {
		temp = (long long)sqrt(num);
		if ( pow(temp,2) == num)
			num = temp;
		else{
			cnt += pow(temp + 1, 2) - num;
			num = (long long)sqrt(pow(temp + 1, 2));
		}
		cnt++;
	}
	return cnt;
}