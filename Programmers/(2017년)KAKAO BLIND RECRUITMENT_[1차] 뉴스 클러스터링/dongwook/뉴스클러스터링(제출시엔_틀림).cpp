
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//vector<string> set1,set2;
int solution(string str1, string str2);
bool cmp(const string &s1, const string &s2);
int main() {
	
	printf("%d\n", solution("FRANCE", "french"));
	printf("%d\n", solution("handshake", "shake hands"));
	printf("%d\n", solution("aa1+aa2", "AAAA12"));
	printf("%d\n", solution("E=M*C^2", "e=m*c^2"));
}
bool cmp(const string &s1, const string &s2) {
	if (s2.compare(s1) == 1)
		return 1;
	else
		return 0;
}
int solution(string str1, string str2) {
	vector<string> set1, set2;
	int answer = 0;

	if (str1.at(0) <= 'Z'&&str1.at(0) >= 'A') {
		str1[0] = str1[0] - ('A' - 'a');
	}
	//printf("\nstr1 : ");
	for (int i = 0; i < str1.length()-1; i++) {
		
		if (str1.at(i+1) <= 'Z'&&str1.at(i + 1) >= 'A') {
			str1[i + 1] = str1[i + 1] - ('A' - 'a');
		}
		if (str1.at(i) <= 'z'&&str1.at(i) >= 'a'&&str1.at(i+1) <= 'z'&&str1.at(i+1) >= 'a') {
			set1.push_back(str1.substr(i, 2));
			//printf("%s ", set1[set1.size()-1]);
		}
		
	}
	//printf("\nstr2 : ");
	if (str2.at(0) <= 'Z'&&str2.at(0) >= 'A') {
		str2[0] = str2[0] - ('A' - 'a');
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		if (str2.at(i + 1) <= 'Z'&&str2.at(i + 1) >= 'A') {
			str2[i + 1] = str2[i + 1] - ('A' - 'a');
		}
		if (str2.at(i) <= 'z'&&str2.at(i) >= 'a'&&str2.at(i + 1) <= 'z'&&str2.at(i + 1) >= 'a') {
			set2.push_back(str2.substr(i, 2));
			//printf("%s ", set2[set2.size()-1]);
		}
	}
	sort(set1.begin(), set1.end(),cmp);
	sort(set2.begin(), set2.end(),cmp);
	int intersection_cnt = 0;
	int union_cnt = 0;
	for (int i = 0, j = 0; i < set1.size() && j < set2.size();) {
		if (set1[i].compare(set2[j]) == 0) {//set1==set2
			intersection_cnt++;
			i++;
			j++;
		}
		else if (set1[i].compare(set2[j]) > 0) {//set1>set2
			j++;
		}
		else {//set1<set2
			i++;
		}
	}

	union_cnt = set1.size() + set2.size() - intersection_cnt;
	float similarity;
	if (union_cnt == 0)
		similarity = 1;
	else
		similarity = (float)intersection_cnt / union_cnt;
	similarity = similarity * 65536;

	//printf("\n합집합수 :  %d, 교집합수 : %d\n", union_cnt, intersection_cnt);
	answer = (int)similarity;
	return answer;
}
