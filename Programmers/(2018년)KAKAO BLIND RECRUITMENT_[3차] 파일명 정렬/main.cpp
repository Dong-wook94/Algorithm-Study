#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

typedef struct FileName{
    string origin;
    string head;
    string num_str;
    int num;
    string tail;
    FileName(string str){
        origin = str;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0'&&str[i]<='9'){//숫자가 처음 나올때
               head = str.substr(0,i);
                transform(head.begin(), head.end(), head.begin(),::tolower);
               str = str.substr(i);
               break;
            }
        }
        int idx=0;
        for(int i=0;i< str.size();i++){
            if(str[i]<'0'||str[i]>'9'){
                idx = i;
                break;
            }
            
        }
        if(idx==0)
            idx = str.size();
        num_str = str.substr(0,idx);
        num = stoi(num_str);
        tail = str.substr(idx);
    }
}FileName;

vector<FileName> fileNames;

bool cmp(FileName f1, FileName f2){
    if(f1.head==f2.head){
        return f1.num<f2.num;
    }
    return f1.head<f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    
    for(int i=0;i<files.size();i++){
        fileNames.push_back(FileName(files[i]));
    }
    stable_sort(fileNames.begin(), fileNames.end(),  cmp);
    
    for(int i=0;i<fileNames.size();i++){
        //cout<<fileNames[i].head<<"///"<<fileNames[i].num_str<<"("<<fileNames[i].num<<")"<<endl;
        answer.push_back(fileNames[i].origin);
    }
    
    return answer;
}


int main(){
    vector<string> a;
    
}

