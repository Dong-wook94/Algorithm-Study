# C++ 자주사용할거같아 만든 function
~~~
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
		token.push_back(str.substr(del_pos[i], del_pos[i + 1] - 
del_pos[i]-1));
	}
	return token;
}
~~~