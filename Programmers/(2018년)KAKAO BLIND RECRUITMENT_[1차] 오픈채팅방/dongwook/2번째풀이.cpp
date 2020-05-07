#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

typedef struct Log{
    string action;
    string user_id;
    Log(string a, string id){
        action = a;
        user_id = id;
    }
}Log;

map<string,string> users;
vector<Log> logs;


vector<string> string_tokenize(string str, char delimeter) {
    vector<string> result;
    string token;
    stringstream ss(str);

    while (getline(ss, token, delimeter)) {
        result.push_back(token);
    }
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i=0;i<record.size();i++){
        vector<string> data = string_tokenize(record[i], ' ');
        if(data[0]=="Enter"){
            users[data[1]] = data[2];
            logs.push_back(Log("Enter",data[1]));
        }else if(data[0] == "Leave"){
            logs.push_back(Log("Leave",data[1]));
        }
        else{
            users[data[1]] = data[2];
        }
        
    }
    
    for(int i=0;i<logs.size();i++){
        string temp = users[logs[i].user_id];
        if(logs[i].action=="Enter"){
            temp += "님이 들어왔습니다.";
        }
        else{
            temp += "님이 나갔습니다.";
        }
        answer.push_back(temp);
        //cout<<temp<<endl;
    }
    return answer;
}
