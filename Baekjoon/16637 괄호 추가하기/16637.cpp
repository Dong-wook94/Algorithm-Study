#include <iostream>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;

long long max_val = LLONG_MIN;
long long cal(long long a, char op, long long b);
void dfs(deque<long long> num, deque<char> op);
int main() {
	long long num;
	char op;
	deque<long long> operand;
	deque<char> oper;
	cin >> N;
	for (int i = 0; i < N / 2; i++) {
		cin >> num;
		operand.push_back(num);
		cin >> op;
		oper.push_back(op);
	}
	cin >> num;
	operand.push_back(num);
	if (operand.size() == 1) {
		printf("%d\n", operand.front());
		return 0;
	}

	else if (operand.size() == 2) {
		long long n1 = operand.front();
		operand.pop_front();
		long long n2 = operand.front();
		operand.pop_front();
		char op1 = oper.front();
		oper.pop_front();
		long long result = cal(n1, op1, n2);
		printf("%d\n", result);
		return 0;
	}

	dfs(operand, oper);
	printf("%d\n", max_val);
}

void dfs(deque<long long> num, deque<char> op) {
	if (op.size() == 1) {//종료조건
		long long n1 = num.front();
		num.pop_front();
		long long n2 = num.front();
		num.pop_front();
		char op1 = op.front();
		op.pop_front();
		long long result = cal(n1, op1, n2);
		if (max_val < result) {
			max_val = result;
		}
		return;
	}
	else if (op.size() == 0) {
		if (max_val < num.front()) {
			max_val = num.front();
		}
		return;
	}
	//dfs
	deque<long long> temp_num = num;
	deque<char> temp_op = op;
	long long n1 = temp_num.front();
	temp_num.pop_front();
	long long n2 = temp_num.front();
	temp_num.pop_front();
	char op1 = temp_op.front();
	temp_op.pop_front();
	temp_num.push_front(cal(n1, op1, n2));
	dfs(temp_num, temp_op);
	temp_num.pop_front();
	long long n3 = temp_num.front();
	temp_num.pop_front();
	long long op2 = temp_op.front();
	temp_op.pop_front();
	temp_num.push_front(cal(n1, op1, cal(n2, op2, n3)));
	dfs(temp_num, temp_op);

}
long long cal(long long a, char op, long long b) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
}