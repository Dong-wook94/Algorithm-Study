#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

int N;
int arr[MAX];
vector<int> cache;
int LIS(void)
{
	cache.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (cache.back() < arr[i]) {//
			cache.push_back(arr[i]);
		}
		else {
			auto it = lower_bound(cache.begin(), cache.end(), arr[i]);
			*it = arr[i];
		}
	}
	return cache.size();
}



int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cout << LIS() << "\n";

	return 0;

}