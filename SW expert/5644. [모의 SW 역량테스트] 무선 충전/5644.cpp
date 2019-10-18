#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

typedef struct BC {
	int row;
	int col;
	int coverage;
	int performance;
	
}BC;

vector<BC> BCs;

int A_move[101];
int B_move[101];
int M, n_BC;
int dir_row[5] = {0,-1,0,1,0};//x,상,우,하,좌
int dir_col[5] = {0,0,1,0,-1};
int result;
bool cmp(BC a, BC b) {
	return a.performance > b.performance;
}
int getDistance(int bc_row,int bc_col, int row, int col) {
	return abs(bc_row - row) + abs(bc_col - col);
}
void Move_Charge(int A_row,int A_col,int B_row,int B_col) {
	for (int t = 0; t <=M; t++) {//매시간마다 A,B
		//cout << "T:"<<t<<"(A : " << A_row << "," << A_col << ") (B:" << B_row << "," << B_col << ")";
		int A_Max_Charge = 0;
		int B_Max_Charge = 0;
		int sum=0;
		vector<BC> A_BC;
		vector<BC> B_BC;
		for (int i = 0; i < BCs.size(); i++) {
			int A_dist = getDistance(BCs[i].row, BCs[i].col, A_row, A_col);
			int B_dist = getDistance(BCs[i].row, BCs[i].col, B_row, B_col);
			if (A_dist <= BCs[i].coverage) {
				A_BC.push_back(BCs[i]);
			}
			if (B_dist <= BCs[i].coverage) {
				B_BC.push_back(BCs[i]);
			}
		}
		
		
		if (A_BC.size() >= 1 && B_BC.size() == 0) {
			sort(A_BC.begin(), A_BC.end(), cmp);
			A_Max_Charge = A_BC[0].performance;
			
		}
		else if(A_BC.size()==0 && B_BC.size()>=1){
			sort(B_BC.begin(), B_BC.end(), cmp);
			B_Max_Charge = B_BC[0].performance;
			
		}
		else {
			for (int i = 0; i < A_BC.size(); i++) {
				for (int j = 0; j < B_BC.size(); j++) {
					int chargeA = A_BC[i].performance;
					int chargeB = B_BC[j].performance;
					if (A_BC[i].row == B_BC[j].row && A_BC[i].col ==B_BC[j].col) {
						chargeA /= 2;
						chargeB /= 2;
					}

					if (sum < chargeA + chargeB) {
						sum = chargeA + chargeB;
						A_Max_Charge = chargeA;
						B_Max_Charge = chargeB;
					}
				}
			}
		}
	
		
		result = A_Max_Charge + B_Max_Charge + result;
		//cout << "   A:" << A_Max_Charge << ",B:" << B_Max_Charge << ",result=" << result << endl;
		A_row = A_row + dir_row[A_move[t]];
		A_col = A_col + dir_col[A_move[t]];
		B_row = B_row + dir_row[B_move[t]];
		B_col = B_col + dir_col[B_move[t]];
	}
}

void Testcase() {
	scanf("%d %d", &M, &n_BC);
	int input;
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		A_move[i] = input;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		B_move[i] = input;
	}
	for (int i = 0; i < n_BC; i++) {
		BC temp;
		scanf("%d %d %d %d", &temp.col, &temp.row, &temp.coverage, &temp.performance);
		BCs.push_back(temp);
	}
	
	Move_Charge(1,1,10,10);

	BCs.clear();

}

int main() {
	//freopen("Text.txt", "r", stdin);
	int testcase;
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		result = 0;
		Testcase();
		printf("#%d %d\n", i, result);
	
	}
}