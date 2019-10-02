# 괄호추가하기
> dfs를 이용한 완전탐색

## 풀이방

deque를 이용하여 앞에서 부터 순차적인 계산을 진행하였다.

~~~c++
deque<long long> operand;
deque<char> oper;
~~~ 
연산자와 피연산자로 이루어진 각각의 deque를 만들어 이용하며

1. 앞의 두수를 괄호친경우
2. 앞의 두수를 괄호치지 않은 경우

이 두가지의 경우로 나눠 dfs를 진행하였다.

## 발생했던 오류
곱셈과 마이너스 연산을 고려하지않아 최댓값 초기화시와 int 사용으로 인해 
오류가 발생하여 최솟값을 long long 의 최솟값 으로 주고 int를 long long 
으로 바꿨다.

백준 16637번 괄호추가하기 : https://www.acmicpc.net/problem/16637	

