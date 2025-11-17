#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string name;
    Node* left;
    Node* right;
    public:
    Node(string element){
        name = element;
        left = right = nullptr;
    }
    
};

void printFolder(Node* root,int level){
    if(root == NULL)return ;

    for(int i=0;i<level;i++){
        cout<<"     ";
    }

    cout<<root->name<<endl;
    printFolder(root->left,level+1);
    printFolder(root->right,level+1);

}
int main() {
    Node* root = new Node("folder-01");

    root->left = new Node("folder-A");

    root->left->left = new Node("folder-A1");
    root->left->right = new Node("folder-A2");


    root->right = new Node("folder-B");
    root->right->left = new Node("folder-B1");
    root->right->right = new Node("folder-B2");

    cout<<"this is going to be the folder "<<endl;
    printFolder(root,0);


    return 0;
}