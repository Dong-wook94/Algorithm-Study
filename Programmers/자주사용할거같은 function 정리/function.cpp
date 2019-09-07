#include<iostream>
#include <string>
#include <vector>

using namespace std;

string Upper2Lower(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] <= 'Z'&&str[i] >= 'A') {
			str[i] = str[i] - ('A' - 'a');
		}
	}
	return str;
}

vector<int> str_find_all_pos(string str, string delimiter) {
	vector<int> del_pos;
	//del_pos.push_back(0);
	for (int i = 0; i < str.size(); i++) {
		if (str.find(delimiter, i) != std::string::npos) {
			int index = str.find(delimiter, i);
			del_pos.push_back(index);
			i = index + 1;
		}
	}
	return del_pos;
}

vector<string> string_tokenize(string str, string delimiter) {
	vector<string> token;
	vector<int> del_pos;
	//token.push_back(str.substr(0, str.find(" ")));
	del_pos.push_back(0);
	for (int i = 0; i < str.size(); i++) {
		if (str.find(delimiter, i) != std::string::npos) {
			int index = str.find(delimiter, i);
			del_pos.push_back(index+1);
			i = index + 1;
		}
		else {
			del_pos.push_back(str.size()+1);
			break;
		}
			
	}
	for (int i = 0; i < del_pos.size()-1; i++) {
		token.push_back(str.substr(del_pos[i], del_pos[i + 1] - del_pos[i]-1));
	}
	return token;
}



int main() {
	string a = "가,나,다,라,마";
	string b = "가 나 다 라 마";
	vector<string> name = string_tokenize(a, ",");
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << endl;
	}
	cout << name[0].size() << endl;
	vector<string> name2 = string_tokenize(b, " ");
	for (int i = 0; i < name.size(); i++) {
		cout << name2[i] << endl;
	}
	cout << name2[0].size() << endl;

	string c = "sdfWRQRqsd";
	c = Upper2Lower(c);
	cout << c << endl;

	vector<int> d = str_find_all_pos(a,",");
	for (int i = 0; i < d.size(); i++) {
		cout << a[d[i]]<< ":"<<d[i] << endl;
	}

}