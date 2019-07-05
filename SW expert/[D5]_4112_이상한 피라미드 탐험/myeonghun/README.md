# [D5] 4112. 이상한 피라미드 탐험

[문제링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWJHmLraeEwDFAUH&categoryId=AWJHmLraeEwDFAUH&categoryType=CODE)

## 알고리즘 분류
- 수학

## 풀이
1. 사실상 보물에서 가든지, 현재 위치에서 가든지 상관없으므로 작은 값과 큰 값으로 분리해서 문제에 접근한다.
2. 해당 보물의 레벨(높이)를 구한다.
3. - 작은 값을 가장 윗점으로 하는 정삼각형 모양에 있는 공간은 높이만큼 이동할 수 있다.
4. - 그리고 그 밖의 범위는 해당 삼각형의 가장 아래 왼쪽, 혹은 아래 오른쪽 중 하나에서의 거리다.

## 결과
|Memory(KB)|Time(ms)|Code|
|-------|----|----|
|3408|4|1327|
