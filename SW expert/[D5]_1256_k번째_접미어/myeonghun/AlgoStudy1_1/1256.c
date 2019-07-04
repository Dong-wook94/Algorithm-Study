#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

int compare(const void *a, const void *b) {
	return(strcmp((char *)a, (char *)b));
}

void solution(char *line, int k) {
	char _subline[400][400] = { 0, };
	char temp[400] = { 0, };
	int i, j, t;
	int l = strlen(line);
	for (i = 0; i < l; i++) {
		t = 0;
		for (j = i; j <= l; j++) {
			_subline[i][t++] = line[j];
		}
	}
	qsort((void *)_subline, l, sizeof(_subline[0]), compare);
	printf("%s\n", _subline[k - 1]);
}

int main(void) {
	int c = 0, i;
	int k = 0;
	char line[400];

	scanf("%d", &c);
	for (i = 0; i < c; i++) {
		scanf("%d", &k);
		scanf("%s", line);
		printf("#%d ", i + 1);
		solution(line, k);
	}
	return 0;
}