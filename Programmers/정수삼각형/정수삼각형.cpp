#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {

    int answer=0;
    vector<vector<int>> dp;
    dp.assign(triangle.size(),vector<int>(triangle.size(),0));
    dp[0][0] = triangle[0][0];
    
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=i;j++){
			dp[i][j] += triangle[i][j];
            if(j==0)
                dp[i][j] += dp[i-1][j];
            else if(j==i)
                dp[i][j] += dp[i-1][j-1];
            else{
                dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
            }
            if(i==triangle.size()-1){
                answer = max(answer, dp[i][j]);
            }
        }
    }

	return answer;
}

int main() {
	printf("%d ", solution({ {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} }));
}