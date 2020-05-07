#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> setA;
vector<string> setB;
vector<string> union_result;
vector<string> inter_result;

string changeLowerCaseStr(string str){
    for(int i=0;i<str.size();i++){
        if(str[i] <='Z' && str[i] >='A')
            str[i] = str[i] -('A'-'a');
    }
    return str;
}

bool isValidSubStr(string str,int i){
    if(str[i]<='z'&&str[i]>='a'&&str[i+1]<='z'&&str[i+1]>='a')
        return true;
    return false;
}
int solution(string str1, string str2) {
    int answer = 0;
    str1 = changeLowerCaseStr(str1);
    str2 = changeLowerCaseStr(str2);
    
    for(int i=0;i<str1.size()-1;i++){
        if(isValidSubStr(str1,i))
            setA.push_back(str1.substr(i,2));
    }
    for(int i=0;i<str2.size()-1;i++){
        if(isValidSubStr(str2,i))
            setB.push_back(str2.substr(i,2));
    }
    sort(setA.begin(),setA.end());
    sort(setB.begin(),setB.end());
    
    set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(union_result));
    set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(inter_result));
    
//    cout<<union_result.size()<<endl;
//    cout<<inter_result.size()<<endl;
    if(union_result.size()==0)
        return 65536;
    double similarity = (double)inter_result.size()/(double)union_result.size();
//    cout<<similarity<<endl;
    answer = similarity*65536;
    
    return answer;
}

int main(){
    string str1 = "FRANCE";
    string str2 = "french";
    cout<<solution(str1,str2)<<endl;
    
}
