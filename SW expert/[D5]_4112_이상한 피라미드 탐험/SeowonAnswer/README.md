# [D5] 4112. 이상한 피라미드 탐험

[문제링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWJHmLraeEwDFAUH&categoryId=AWJHmLraeEwDFAUH&categoryType=CODE)

## 알고리즘 분류
- 수학

## 아이디어
1. 숫자들을 삼각형좌표 (row, col)로 둘 수 있다. (따로 식이 있음)
	- \\(row = ceil(\frac {-1 + \sqrt{1+8*n}} 2)\\) 
	- \\(col = \frac {row*(row+1)} 2 - n\\)
	- hint : k번째 줄의 가장 끝자리 수 = \\( \frac {k(k+1)} 2 \\)

2. \\((i, j)\\)에서 이동할 수 있는 경우는 다음과 같다.
	- \\((i-1, j-1)\\)
	- \\((i-1, j)\\)
	- \\((i, j-1)\\)
	- \\((i, j+1)\\)
	- \\((i+1, j)\\)
	- \\((i+1, j+1)\\)

3. 먼저 대각선으로 갈 수 있는 최대로 간 다음 대각선이 아닌 방법으로 갈 때 횟수를 세면 된다. (자세한 계산법은 코드 참조)

## Time & Space complexity
- 수학으로 풀면 이렇다..
- Time: O(1)
- Space: O(1)

- 제출이력을 보니까 BFS나 탐색으로 푼 사람도 있는 듯.. 규칙부터 찾아보자!

## 결과
|Language|Memory(KB)|Time(ms)|Code|
|-------|-------|----|----|
|C++|12,492|6|799|
|C|292|4|647|

- 확실히 같은 로직일 때 C가 더 빠르다. 클래스같이 문법적으로 이득보는 일 없으면 C로 내면 제격
- 메모리에서도 확실히 차이나는데 C++은 클래스를 사용하였고 test()함수 내 변수(Stack영역)를 사용하여 계산했는데 지역변수를 호출할 때 마다 메모리를 계속 사용하는 듯(Random Access한 구역 다 계산하는 듯)
- 그래서 알고할때는 왠만하면 전역(Heap/static)쓰자!
- 해석+코딩은 체감상 25분, 81등/350
