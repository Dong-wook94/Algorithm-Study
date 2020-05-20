#include <iostream>
#include <vector>
using namespace std;

typedef struct treeNode{
    int edge,num;
    treeNode(){}
    treeNode(int e, int n){
        edge = e; num = n;
    }
}treeNode;

int numNode;
vector<vector<treeNode>> graph;

int max_distance_node=0;
int max_distance=0;

void dfs(int node, int edgeLength,vector<bool> visited){
    if(max_distance<edgeLength){
        max_distance = edgeLength;
        max_distance_node = node;
    }
    for(int i=0;i<graph[node].size();i++){
        int next_node = graph[node][i].num;
        if(!visited[next_node]){
            visited[next_node] = true;
            dfs(next_node, edgeLength + graph[node][i].edge,visited);
        }
    }
}

int main() {
    vector<bool> visited;
    cin>>numNode;
    graph.assign(numNode+1,vector<treeNode>(0,treeNode(0,0)));
    visited.assign(numNode+1, false);
    
    for(int i=0;i<numNode;i++){
        int node;
        cin>>node;
        while(1){
            int inputNode;
            cin>>inputNode;
            if(inputNode ==-1)
                break;
            int edge;
            cin>>edge;
            graph[node].push_back(treeNode(edge,inputNode));
        }
    }
    
    visited[1] = true;
    dfs(1,0,visited);
    visited[1] = false;
    
    int start = max_distance_node;
    max_distance_node = 0;
    
    
    visited[start] = true;
    dfs(start ,0, visited);
    visited[start] = false;
    
    cout<<max_distance<<endl;
    
    return 0;
}
