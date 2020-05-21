
#include <stdio.h>

using namespace std;

int N,M;

int parent[1000001];


void initSet(){
    for(int i=0;i<=N;i++)
        parent[i] = i;
}

int find(int num){
    if (num == parent[num])
        return num;
    else{
        parent[num] = find(parent[num]);
        return parent[num];
    }
}

int main() {
    scanf("%d %d",&N,&M);
    initSet();
    for(int i=0;i<M;i++){
        int mode,num1,num2;
        scanf("%d %d %d",&mode,&num1,&num2);
        if(mode==0){
            num1 = find(num1);
            num2 = find(num2);
            if(num1!=num2)
                parent[num2]=num1;
        }
        else{
            num1 = find(num1);
            num2 = find(num2);
            if(num1==num2)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    
    return 0;
}
