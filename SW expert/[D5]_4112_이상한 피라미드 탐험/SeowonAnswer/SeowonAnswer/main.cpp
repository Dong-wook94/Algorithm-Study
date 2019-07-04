#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int a, b;
int ax, bx;
int ay, by;

void test();

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("#%d ", i);
		test();
	}
	return 0;
}

void test() {
	scanf("%d %d", &a, &b);
	ax = ceil((sqrt(8 * a + 1) - 1) / 2);
	ay = ax * (ax + 1) / 2 - a;
	bx = ceil((sqrt(8 * b + 1) - 1) / 2);
	by = bx * (bx + 1) / 2 - b;
	
	int ret = 0;
	if (ay > by && ax > bx) {
		if (ay - by > ax - bx)
			ret = ay - by;
		else
			ret = ax - bx;
	}
	else if (ay < by && ax < bx) {
		if (by - ay > bx - ax)
			ret = by - ay;
		else
			ret = bx - ax;
	}
	else
		ret = abs(ax - bx) + abs(ay - by);

	printf("%d\n", ret);
}



