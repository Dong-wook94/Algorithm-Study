#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 99999999
using namespace std;

int score[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            score[i][j] = MAX;
        }
    }
    
    for(int i=0;i<results.size();i++){
        int a = results[i][0];
        int b= results[i][1];
        score[a][b] = 1;
    }
     
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                score[i][j] = min(score[i][j],score[i][k]+score[k][j]);
            }
        }
    }
    
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            cout<<score[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    
    for( int i=1;i<=n;i++){
        bool check=true;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(score[i][j]==MAX && score[j][i] ==MAX){
                check = false;
                break;
            }
        }
        if(check)
            answer++;
    }
    
    return answer;
}

int main(){
    cout<<solution(5,{{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}})<<endl;
}
