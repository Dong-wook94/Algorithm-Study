#include <iostream>

using namespace std;

class TreeNode{
    friend class Tree;
private:
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
public:
    TreeNode(char d){
        data = d;
        leftChild = NULL;
        rightChild = NULL;
    }
};
TreeNode* node[27]={NULL,};
class Tree{
    
private:
    TreeNode* root;
public:
    Tree():root(NULL){};
    ~Tree(){};
    void setRoot(){
        root = node[0];
    }
    void connectTree(char V, char L, char R){
        int V_idx = V-'A';
        if(L=='.'){
            node[V_idx]->leftChild = NULL;
        }else{
            node[V_idx]->leftChild = node[L-'A'];
        }
        if(R=='.'){
            node[V_idx]->rightChild = NULL;
        }
        else{
            node[V_idx]->rightChild = node[R-'A'];
        }
    }
    TreeNode* getRoot(){
        return root;
    }
    
    void preorder(TreeNode* ptr){
        if(ptr){
            cout<<ptr->data;
            preorder(ptr->leftChild);
            preorder(ptr->rightChild);
        }
    }
    void postorder(TreeNode* ptr){
         if (ptr) {
            postorder(ptr->leftChild);
            postorder(ptr->rightChild);
            cout<<ptr->data;
        }
    }
    void inorder(TreeNode* ptr){
        if (ptr) {
            inorder(ptr->leftChild);
            cout<<ptr->data;
            inorder(ptr->rightChild);
            
        }
    }
};

int N;
Tree* tree;
int main() {
    cin>>N;
    for(int i=0;i<N;i++){
        node[i] = new TreeNode('A'+i);
    }
    tree = new Tree();
    if(node[0]!=NULL){
        tree->setRoot();
    }
    
    for(int i=0;i<N;i++){
        char V,L,R;
        cin>>V>>L>>R;
        tree->connectTree(V,L, R);
    }
    tree->preorder(tree->getRoot());
    cout<<"\n";
    tree->inorder(tree->getRoot());
    cout<<"\n";
    tree->postorder(tree->getRoot());
    cout<<"\n";
}
