#include <stdio.h>
#include <stdlib.h>

typedef struct Pos {
	int level;
	int index;
}Pos;

int search_treasure(int i_pos, int t_pos);
Pos get_pos(int i_pos);

Pos source, destination;

int main() {
	int testcase;
	int minji_pos, treasure_pos;
	int time;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		scanf("%d %d", &minji_pos, &treasure_pos);
		time = search_treasure(minji_pos, treasure_pos);

		printf("#%d %d\n", t, time);
	}
}

int search_treasure(int i_pos, int t_pos) {
	int time;
	int level_gap, index_gap;
	if (i_pos < t_pos) {
		source = get_pos(i_pos);
		destination = get_pos(t_pos);
	}
	else {
		destination = get_pos(i_pos);
		source = get_pos(t_pos);
	}
	level_gap = destination.level - source.level;
	index_gap = abs(source.index - destination.index);
	if (level_gap <= index_gap) {
		time = index_gap;
		if (source.index > destination.index)
			time += (destination.level - source.level);
	}
	else {
		time = level_gap;
		if (source.index > destination.index)
			time += (source.index - destination.index);
	}
	return time;
}
Pos get_pos(int i_pos) {
	int level = 1;
	int level_last = 1;
	Pos pos;
	while (1) {
		if (i_pos > level_last) {
			level_last = level_last + level + 1;
			level++;
		}
		else {
			pos.level = level;
			pos.index = i_pos - (level_last - level + 1);
			return pos;
		}
	}
}