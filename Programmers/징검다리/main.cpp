#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = INT_MAX;
    
    int left=0,right=distance;
    
    sort(rocks.begin(),rocks.end());
    
    
    while(left<=right){
        
        int prev =0;// 시작지점
        int mid = (left+right)/2;
        int removed_cnt=0;
        int min_distance = INT_MAX;
        for(int i=0;i<rocks.size();i++){
            if(rocks[i] - prev < mid)
                removed_cnt++;
            else{
                min_distance = min(min_distance, rocks[i] - prev);
                prev = rocks[i];
            }
        }
        
        if(removed_cnt > n){ //제거해야될 수보다 더많이 제거했을때. 거리를 줄여야됨
            right = mid-1;
        }
        else{ // 제거한 돌의 개수가 기준보다 적다. 거리 기준을 높여야 된다.
            answer = min_distance;
            left = mid + 1;
        }
    }
    
    
    return answer;
}
