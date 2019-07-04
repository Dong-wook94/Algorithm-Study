#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define SWAP(X, Y, T) { T = X; X = Y; Y = T; }
typedef class String {
public:
	char string[401];
	int length;
	String() {}
	String(char* str) {
		int i;
		for (i = 0; str[i]; i++)
			string[i] = str[i];
		string[i] = '\0';
		length = i;
	}

	String(char* str, int start) {
		int i, j = 0;
		for (i = start; str[i]; i++)
			string[j++] = str[i];
		string[j] = '\0';
		length = j;
	}

	bool operator<(const String& s) const {
		int i;
		for (i = 0; s.string[i] && string[i]; i++) {
			if (string[i] != s.string[i]) return string[i] < s.string[i];
		}
		return string[i] < s.string[i];
	}
	bool operator>(const String& s) const {
		int i;
		for (i = 0; s.string[i] && string[i]; i++) {
			if (string[i] != s.string[i]) return string[i] > s.string[i];
		}
		return string[i] > s.string[i];
	}
} String;

String strings[400];
void test();
void quickSort(int s, int e);

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
	int k;
	char str[401];
	scanf("%d\n", &k);
	scanf("%s", str);
	int i;
	for (i = 0; str[i]; i++)
		strings[i] = String(str, i);

	if (k > i) {
		printf("none\n");
		return;
	}

	quickSort(0, i - 1);
	printf("%s\n", strings[k - 1].string);
}

void quickSort(int s, int e) {
	String temp;
	if (s > e) return;
	int pivot = (s + e) / 2;
	SWAP(strings[pivot], strings[e], temp);
	pivot = e;
	int i = s, j = e - 1;

	while (true) {
		while (i <= j && strings[i] < strings[pivot]) i++;
		while (i <= j && strings[j] > strings[pivot]) j--;

		if (i > j) {
			SWAP(strings[i], strings[pivot], temp);
			pivot = i;
			break;
		}
		SWAP(strings[i], strings[j], temp);
	}

	quickSort(s, pivot - 1);
	quickSort(pivot + 1, e);
}