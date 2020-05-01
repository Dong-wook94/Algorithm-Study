#include <string>
#include <vector>
#include <iostream>
using namespace std;

string number="0123456789ABCDEF";

string nNumber(int num, int n){
    string result="";
    while(num/n!=0){
        int remainder = num%n;
        result = number[remainder]+result;
        num = num/n;
    }
    result = number[num%n]+result;
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string totalStr = "";
    for(int i=0;i<t*m;i++){
        totalStr += nNumber(i, n);
    }
    for(int i=p-1;answer.size()<t;i=i+m){
        answer += totalStr[i];
        
    }
    
    return answer;
}

int main(){
    int n=16;
    int t=16;
    int m=2;
    int p=1;
    cout<<solution(n,t,m,p)<<endl;
}
