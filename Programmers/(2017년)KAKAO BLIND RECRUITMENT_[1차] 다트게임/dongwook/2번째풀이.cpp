#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<int> num;

int solution(string dartResult) {
    int answer = 0;
    
    for(int i=0;i<dartResult.size();i++){
        switch(dartResult[i]){
            case 'S':
                break;
            case 'D':
                num[num.size()-1] = pow(num[num.size()-1],2);
                break;
            case 'T':
                num[num.size() - 1] = pow(num[num.size() - 1], 3);
                break;
            case '*':
                num[num.size() - 1] *= 2;
                 if(num.size()>1)
                     num[num.size() - 2] *= 2;
                break;
            case '#':
                num[num.size() - 1] *= (-1);
                break;
            default:
                if(dartResult[i]=='1'){
                    if (dartResult[i + 1] == '0') {
                        num.push_back(10);
                        i++;
                    }
                    else
                        num.push_back(1);
                }
                else{
                    int temp = dartResult[i]-'0';
                    num.push_back(temp);
                }
                break;
                
        }
    }
    
    for (int i = 0; i < num.size(); i++) {
        answer += num[i];
        //cout<<num[i]<<endl;
    }
    return answer;
}
int main() {
    string s1= "1D2S#10S";
    cout<<solution(s1)<<endl;
}
