#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> result;
    for(int i=0;i<arr1.size();i++){
        int temp = arr1[i]|arr2[i];
        result.push_back(temp);
    }
    
    for(int i=0;i<result.size();i++){
        string temp;
        for(int mask=1<<(n-1);mask>0;mask= mask>>1){
//            cout<<mask<<":"<<(result[i]&mask)<<endl;
            if(result[i]&mask){
                temp +="#";
            }
            else{
                temp +=" ";
            }
        }
        answer.push_back(temp);
//        cout<<temp<<endl;
    }
    
    return answer;
}
