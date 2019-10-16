# 5658. [모의 SW 역량테스트] 보물상자 비밀번호

> set라이브러리, string라이브러리 사용



## set 사용
중복제거를 위한 set 라이브러리 사용

set 내림차순으로 출력시 rbegin, rend 사용하면된다.
set은 `자동 오름차순 정렬`이기때문. 

그리고 set<int>::iterator 대신 타입캐스팅 자동으로 해주는auto 사용하면 
편하다.

~~~c++
for (auto iter = num_set.rbegin(); iter != num_set.rend(); iter++) {
			if (cnt == size_order-1) {
				cout << *iter << endl;
				break;
			}
			cnt++;
		}
~~~



## string to int

문자 입력으로 들어온 16진수를 손쉽게 int로 바꿀수 있다.

~~~c++
//example
stoi(temp, nullptr, 16);
~~~

첫번째 인자는 `const string& str` : 변경할 문자열이 들어감

두번째 인자는 `size_t* idx=0`  : 포인터타입. 맨 첫번째 부터 숫자가 아닌 부분까지 해서 그부분의 포인터를 걸러준다.

세번째 인자 : 진수

**: base 는 진수**를 뜻합니다.

: default는 10으로 10진수입니다.

: **string 안에 있는 숫자의 표현이 어떤것이다 라고 base 를 통해서 알려주는 것** 입니다.

: binary (2진수)이라면 2를 넣고

: octal (8진수)이라면 8을 넣고

: decimal (10진수)는 기본이니까 넣지 않아도 됩니다. 굳이 10을 넣는다 해도 무관합니다.

: hexadecimal (16진수)이라면 16을 넣으시면 됩니다.



## Reference

stoi :  https://blockdmask.tistory.com/333 