#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <set>

using namespace std;

int n_number;
int size_order;
string input_num;
set<int> num_set;
void Testcase() {
	
	scanf("%d %d ", &n_number, &size_order);
	cin >> input_num;
	for (int i = 0; i < n_number / 4; i++) {
		input_num += input_num[i];
	}
	//한바퀴위해 앞의두개 뒤에도 추가
	for (int i = 0; i < n_number; i++) {
		string temp = input_num.substr(i, n_number/4).c_str();
		//cout << temp <<" : "<<stoi(temp,nullptr,16)<< endl;
		num_set.insert(stoi(temp, nullptr, 16));
	}
	
}

int main(){
	freopen("Text.txt", "r", stdin);
	int testcase;
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		Testcase();
		cout << "#" << i << " ";
		int cnt = 0;
		for (auto iter = num_set.rbegin(); iter != num_set.rend(); iter++) {
			if (cnt == size_order-1) {
				cout << *iter << endl;
				break;
			}
			cnt++;
		}
		num_set.clear();
	}

}