#include <iostream>
#include <algorithm>
#define SWAP(X, Y, T) {T = X; X = Y; Y = T;}

using namespace std;

typedef class Ball {
public:
	int num;
	int color;
	int size;
	Ball() {}
	Ball(int num, int color, int size) {
		this->num = num;
		this->color = color;
		this->size = size;
	}
	bool operator<(const Ball& b) const {
		return size < b.size;
	}
	bool operator>(const Ball& b) const {
		return size > b.size;
	}
} Ball;

Ball balls[200000];
int answer[200000];
int sumOfColor[200001];
int total = 0;
Ball temp;

int main() {
	int n;
	int color = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &balls[i].color, &balls[i].size);
		balls[i].num = i;
		color = color < balls[i].color ? balls[i].color : color;
		total += balls[i].size;
		sumOfColor[balls[i].color] += balls[i].size;
	}

	sort(balls, balls+n, greater<Ball>());
	
	for (int i = 0; i < n; i++) {
		int ans = total - sumOfColor[balls[i].color];
		int ans2 = 0;
		for (int j = i+1; (balls[i].size == balls[j].size && j < n); j++) {
		    if(balls[i].color != balls[j].color)
				ans2 += balls[i].size;
        }
		answer[balls[i].num] = ans - ans2;
		total -= balls[i].size;
		sumOfColor[balls[i].color] -= balls[i].size;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", answer[i]);
    
    return 0;
}
