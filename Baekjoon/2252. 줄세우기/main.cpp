#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;

queue<int> q;
vector<vector<int>> graph;
vector<int> cnt_indegree;
int main() {
    
    scanf("%d %d",&N,&M);
    
    graph.assign(N+1, vector<int>(0,0));
    cnt_indegree.assign(N+1, 0);
    for(int i=0;i<M;i++){
        int from,to;
        scanf("%d %d",&from,&to);
        graph[from].push_back(to);
        cnt_indegree[to]++;
    }
    
    for(int i=1;i<=N;i++){
        if(cnt_indegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        printf("%d ",node);
        for(int i=0;i<graph[node].size();i++){
            cnt_indegree[graph[node][i]]--;
            if(cnt_indegree[graph[node][i]]==0){
                q.push(graph[node][i]);
            }
        }
        graph[node].clear();
    }
    
    return 0;
}
