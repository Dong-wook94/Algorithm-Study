#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct Magnetic {
	int pos;
	int force;
}Magnetic;

vector<Magnetic> m_obj;
vector<double> point;
void Test(int t);
void Cal_point();
bool cmp(const Magnetic &m1, const Magnetic &m2);
void b_search(int turn);
int main() {
	int testcase;

	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		Test(t);
		
	}
}

void Test(int t) {
	int num;
	Magnetic temp;
	scanf("%d", &num);
	temp.force = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp.pos);
		m_obj.push_back(temp);
	}
	for (int i = 0; i < num; i++) {
		scanf("%d", &m_obj[i].force);
	}
	printf("#%d ", t);
	point.assign(num - 1, 0);
	Cal_point();
	m_obj.clear();
	point.clear();

}
void Cal_point() {

	sort(m_obj.begin(), m_obj.end(), cmp);
	for (int i = 0; i < point.size(); i++) {
		b_search(i);
	}
}
bool cmp(const Magnetic &m1, const Magnetic &m2) {
	return m1.pos < m2.pos;
}
void b_search(int turn) {
	double left = m_obj[turn].pos;
	double right = m_obj[turn+1].pos;
	double mid;
	double l_sum, r_sum;
	double before_mid=0;
	while (1) {
		mid = (left + right) / 2.0;
		if (before_mid / pow(0.1, 12.0) == mid / pow(0.1, 12.0)) {
			printf("%.10lf\n", mid);
			break;
		}
		l_sum = 0;
		r_sum = 0;
		for (int i = 0; i <= turn; i++) {
			l_sum += m_obj[i].force / pow((m_obj[i].pos - mid), 2.0);
		}
		for (int i = turn + 1; i < m_obj.size(); i++) {
			r_sum += m_obj[i].force / pow((m_obj[i].pos - mid), 2.0);
		}
		before_mid = mid;
		if (l_sum > r_sum)
			left = mid;
		else if(l_sum < r_sum)
			right = mid;
		else {
			printf("%.10lf\n", mid);
			break;
		}
	}
}