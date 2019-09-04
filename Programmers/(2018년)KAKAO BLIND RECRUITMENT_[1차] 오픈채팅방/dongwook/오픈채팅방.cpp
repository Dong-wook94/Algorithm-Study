#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;



typedef struct message {
	string userid;
	string msg;
}message;

vector<message> chat;
map<string, string> user;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	message msg_temp;
	string temp;
	//printf("%d",record.size());

	for (int i = 0; i < record.size(); i++) {
		msg_temp.msg = record[i].substr(0, record[i].find(" "));
		//   cout<<msg_temp.msg<<endl;
		temp = record[i].substr(record[i].find(" "));
		if (msg_temp.msg == "Enter") {
			msg_temp.userid = temp.substr(1, temp.find(" ", 1));
			//   cout<<temp<<endl;
			  // cout<<"user id : "<<msg_temp.userid<<endl;
			user[msg_temp.userid] = temp.substr(temp.find(" ", 1) + 1);
			// cout<<"nickname :"<<msg_temp.nickname<<endl;
			chat.push_back(msg_temp);
		}
		else if (msg_temp.msg == "Leave") {
			msg_temp.userid = temp.substr(1, temp.find(" ", 1)) + " ";
			//cout << "leave user id :" << msg_temp.userid << endl;
			chat.push_back(msg_temp);
		}
		else if (msg_temp.msg == "Change") {
			msg_temp.userid = temp.substr(1, temp.find(" ", 1));
			//  cout<<temp<<endl;
			//  cout<<"user id : "<<msg_temp.userid<<endl;
			user[msg_temp.userid] = temp.substr(temp.find(" ", 1) + 1);
			//    cout<<"nickname :"<<msg_temp.nickname<<endl;

			chat.push_back(msg_temp);
		}
	}
	for (std::map<string, string>::iterator iter = user.begin(); iter != user.end(); iter++)
	{
		//cout << "Key : " << iter->first << "Value : " << iter->second << endl;
	}
	for (int i = 0; i < chat.size(); i++) {
		//cout<<chat[i].msg<<" : "<<chat[i].userid<<","<<user[chat[i].userid]<<endl;
		if (chat[i].msg == "Enter") {
			temp = user[chat[i].userid] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(temp);
			//cout << user[chat[i].userid] << "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù." << endl;
		}
		else if (chat[i].msg == "Leave") {
			temp = user[chat[i].userid] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(temp);
			//cout << user[chat[i].userid] << "´ÔÀÌ ³ª°¬½À´Ï´Ù." << endl;
		}

	}

	return answer;
}