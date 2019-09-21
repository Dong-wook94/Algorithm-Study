#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



long long solution(int n, vector<int> times) {
	long long min_time = 0;


	sort(times.begin(), times.end());


	long long low = 1;
	long long high = (long long)times[times.size() - 1] * (long long)n;
	min_time = high;
	long long mid = (low + high) / 2;
	while (1) {
		if (low == mid || high == mid)
			break;
		mid = (low + high) / 2;
		long long cnt = 0;
		for (int i = 0; i < times.size(); i++) {
			cnt += mid / times[i];
		}
		if (cnt < n)
			low = mid + 1;
		else {
			if (min_time > mid)
				min_time = mid;
			high = mid - 1;
		}
	}



	return min_time;
}