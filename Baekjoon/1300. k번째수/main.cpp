
#include <stdio.h>
#include <algorithm>

using namespace std;

long long N;
long long k;

long long getMidIndex(long long mid){
    long long cnt=0;
    for (long long i=1;i<=N;i++){
        cnt+=min(N,mid/i);
    }
    return cnt;
}
int main() {
    scanf("%lld %lld",&N,&k);

    
    long long left =1, right = N*N;
    long long result=1;
    while(left<=right){
        long long mid = (left+right)/2;
        if(getMidIndex(mid)>=k){
            result = mid;
            right = mid -1;
        }
        else{
            left = mid +1;
        }
    }
    printf("%lld\n",result);
    
    return 0;
}
