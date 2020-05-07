#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<bool>> checkBlock;
bool change_flag = true;
void checkSameBlock(int i, int j, vector<string> board){
    if(board[i][j]=='0')
        return;
    if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]){
        change_flag = true;
        checkBlock[i][j] = checkBlock[i][j+1] = checkBlock[i+1][j] = checkBlock[i+1][j+1] = true;
    }
}

void initCheckBlock(){
    for(int i=0;i<checkBlock.size();i++){
        for(int j=0;j<checkBlock[i].size();j++){
            checkBlock[i][j] = false;
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    
    checkBlock.assign(m, vector<bool>(n,false));
    while(change_flag){
        change_flag = false;
        initCheckBlock();
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                checkSameBlock(i, j, board);
            }
        }
//        cout<<"삭제전"<<endl;
//        for(int i=0;i<board.size();i++){
//            cout<<board[i]<<endl;
//        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(checkBlock[i][j]){
                    answer++;
                    for(int k=i;k>0;k--){
                        board[k][j] = board[k-1][j];
                        board[k-1][j] ='0';
                    }
                }
            }
        }
//        cout<<"삭제후"<<endl;
//        for(int i=0;i<board.size();i++){
//            cout<<board[i]<<endl;
//        }
    }
    
    return answer;
}
