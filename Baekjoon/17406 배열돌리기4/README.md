# 배열 돌리기4
> dfs를 이용한 순서 배치 + 배열회전 알고리즘

배열 회전시 모서리의 위치에 도달할시 방향을 변경하는 방법으로 회전 
함수를 짰다. 괜찮은 방법이니 나중에 배열을 회전시키는 문제에 참고하여 
적용하여도 좋을것 같다.

## 모서리 체크 함수
~~~c++
int check_edge(int next_row, int next_col, int row, int col, int 
rotate_size) {
	if (next_row == row + rotate_size && next_col == col + 
rotate_size) {
		return 1;
	}
	else if (next_row == row - rotate_size && next_col == col + 
rotate_size) {
		return 1;
	}
	else if (next_row == row - rotate_size && next_col == col - 
rotate_size) {
		return 1;
	}
	else if (next_row == row + rotate_size && next_col == col - 
rotate_size) {
		return 1;
	}
	else {
		return 0;
	}
}
~~~

## 배열 회전함수
~~~c++
void move_array(int row, int col, int rotate_size) {
	for (int i = 1; i <= rotate_size; i++) {
		int temp = A[row - i][col - i];
		int d = 0;
		int cur_row = row - i;
		int cur_col = col - i;
		int next_row = cur_row + dir_row[d];
		int next_col = cur_col + dir_col[d];
		while (1) {
			if (next_row == row - i && next_col == col - i) 
{
				A[cur_row][cur_col] = temp;
				break;
			}
			A[cur_row][cur_col] = A[next_row][next_col];
			//print_map();
			cur_row = next_row;
			cur_col = next_col;
			next_row = cur_row + dir_row[d];
			next_col = cur_col + dir_col[d];
			if (check_edge(next_row, next_col, row, col, i)) 
{
				d = (d + 1) % 4;
			}
		}
	}
}
~~~
 
