#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;



typedef struct Customer {
	int num;
	int arrival_time;
	int receptionDesk;
	int repairDesk;
	Customer() {}
	Customer(int n, int a) {
		num = n;
		arrival_time = a;
		receptionDesk = -1;
		repairDesk = -1;
	}
}Customer;

typedef struct DeskInfo {
	int time;
	int origin_time;
	int customer_num;
}DeskInfo;


typedef struct Desk {
	int size;
	int time;
	queue<Customer> wait_q;
	DeskInfo desk[10];
}Desk;
int n_customer, target_customer_reception, target_customer_repair;

Desk reception;
Desk repair;
int result;
vector<Customer> customers;
int end_flag;
void Repair_Process() {
	while (!repair.wait_q.empty()) {
		int full = 1;
		for (int i = 0; i < repair.size; i++) {
			if (repair.desk[i].customer_num == -1) {
				full = 0;
				repair.desk[i].customer_num = repair.wait_q.front().num;
				customers[repair.desk[i].customer_num].repairDesk = i;
				repair.desk[i].time = repair.desk[i].origin_time;//시간 count
				repair.wait_q.pop();
				end_flag--;
				break;
			}
		}
		if (full == 1)
			break;
	}
}

void Reception_Process() {
	while (!reception.wait_q.empty()) {
		int full = 1;
		for (int i = 0; i < reception.size; i++) {
			if(reception.desk[i].customer_num == -1) {
				full = 0;
				reception.desk[i].customer_num = reception.wait_q.front().num;
				customers[reception.desk[i].customer_num].receptionDesk = i;
				reception.desk[i].time = reception.desk[i].origin_time;//시간 count
				reception.wait_q.pop();
				break;
			}
		}
		if(full==1)
			break;
	}

	
}
void TimeProcess() {
	for (int i = 0; i < reception.size; i++) {
		if (reception.desk[i].customer_num != -1) {
			reception.desk[i].time--;
			if (reception.desk[i].time == 0) {
				repair.wait_q.push(customers[reception.desk[i].customer_num]);
				reception.desk[i].customer_num = -1;
			}
		}
		
	}
	for (int i = 0; i < repair.size; i++) {
		if (repair.desk[i].customer_num != -1) {
			repair.desk[i].time--;
			if (repair.desk[i].time == 0) {
				repair.desk[i].customer_num = -1;
			}
		}
		
	}
}
void Process() {
	int front = 0;
	end_flag = customers.size();
	for (int time = 0; ;time++) {
		if (front < n_customer) {
			while (front <n_customer && customers[front].arrival_time <= time) {
				reception.wait_q.push(customers[front]);
				front++;
			}
		}
		if (!reception.wait_q.empty()) {
			Reception_Process();
		}
		if (!repair.wait_q.empty()) {
			Repair_Process();
		}
		TimeProcess();
		if (front >= n_customer&&end_flag==0) {
			break;
		}
	}
}

void Testcase() {
	result = 0;
	//customers.push_back(Customer(i, 0);
	scanf("%d %d %d %d %d", &reception.size, &repair.size, &n_customer, &target_customer_reception, &target_customer_repair);
	for (int i = 0; i < reception.size; i++) {
		scanf("%d", &reception.desk[i].origin_time);
	}
	for (int i = 0; i < repair.size; i++) {
		scanf("%d", &repair.desk[i].origin_time);
	}
	while (!reception.wait_q.empty())
		reception.wait_q.pop();
	while (!repair.wait_q.empty())
		repair.wait_q.pop();
	for (int i = 0; i < 10; i++) {
		reception.desk[i].time = 0;
		reception.desk[i].customer_num = -1;
		repair.desk[i].time = 0;
		repair.desk[i].customer_num = -1;
	}
	for (int i = 0; i < n_customer; i++) {
		int input;
		scanf("%d", &input);
		customers.push_back(Customer(i, input));
	}

	Process();
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].receptionDesk+1 == target_customer_reception && customers[i].repairDesk+1 == target_customer_repair) {
			result += (i + 1);
		}
	}
	if (result == 0)
		result = -1;
	customers.clear();
}

int main(){
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <=testcase; i++) {
		Testcase();
		printf("#%d %d\n", i, result);
	}
}