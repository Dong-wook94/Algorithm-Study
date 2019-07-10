#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef struct Position {
	int x;
	int y;
}Position;
Position home;
Position company;
vector<Position> customer;
vector<int> order;
int n_customer;
int MinCost();
int main() {
	int testcase;

	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		scanf("%d", &n_customer);
		printf("#%d %d\n",t,MinCost());
		customer.clear();
		order.clear();
	}
}

int MinCost() {
	Position temp;
	int min = 999999;
	int distance = 0;
	scanf("%d %d", &home.x, &home.y);
	scanf("%d %d", &company.x, &company.y);
	for (int i = 0; i < n_customer; i++) {
		scanf("%d %d", &temp.x, &temp.y);
		customer.push_back(temp);
		order.push_back(i);
	}
	//sort(customer.begin(), customer.end());
	do {
		distance += abs(customer[order[0]].x - home.x);
		distance += abs(customer[order[0]].y - home.y);
		for (int i = 0; i < customer.size()-1; i++) {
			distance += abs(customer[order[i+1]].x - customer[order[i]].x);
			distance += abs(customer[order[i + 1]].y - customer[order[i]].y);
		}
		distance += abs(customer[order[order.size()-1]].x - company.x);
		distance += abs(customer[order[order.size() - 1]].y - company.y);
		if (min > distance)
			min = distance;
		distance = 0;
	} while (next_permutation(order.begin(), order.end()));
	return min;
}