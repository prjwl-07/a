#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    class Node* left;
    class Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }

    Node(int val,Node* left,Node* right){
        left = left;
        right = right;
        data = val;
    }
};

//to insert the node
Node* insertNode(Node* root,int val){
    if(root == NULL){
        root = new Node(val);
        return root ;
    }
    if(val < root->data){
        root->left = insertNode(root->left,val);
    }
    else{
        root->right = insertNode(root->right,val);
    }
    return root;
}
//to create the tree
Node* createBst(int arr[],int n){
    Node* root = nullptr;
    for(int i=0;i<n;i++){
        root = insertNode(root,arr[i]);
    }
    return root ;
}
// to make make preorder traversal
void preOrder(Node* root){
    if(root == NULL)return;
    
    cout<<root->data<<" "<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL)return;
    
    inOrder(root->left);
    cout<<root->data<<" "<<endl;
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL)return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" "<<endl;
}

vector<int> bfs(Node* root){
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* element = q.front();
        q.pop();
        if(element->left)q.push(element->left);
        if(element->right)q.push(element->right);
        ans.push_back(root->data);
    }
    return ans;
}

int search(Node* root,int key){
    if(root == NULL)return -1;
    if(root->data < key){
        return search(root->right,key);
    }
    else if(root->data > key){
        return search(root->left,key);
    }
    else 
    return key;
}


int main(){
    int n;
    cout<<"enter the no of elements you are going to add in the tree:";
    cin>>n;
    cout<<"now enter the elements:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* root = createBst(arr,n);
    
    int choice;
    cout<<"enter the your choice:"<<endl;
    cout<<"1 for inorder"<<endl<<"2 for preorder"<<endl<<"3 for postorder"<<endl<<"4 for levelorder traversal:"<<endl<<"5 for search"<<endl;
    cin>>choice;

    if(choice == 1){
        cout<<"Inorder Traversal:"<<endl;
        inOrder(root);
    }
    else if(choice == 2){
        cout<<"preorder Traversal:"<<endl;
        preOrder(root);
    }
    else if(choice == 3){
        cout<<"postorder Traversal:"<<endl;
        postOrder(root);
    }
    else if(choice == 4){
        cout<<"level order Traversal:"<<endl;
        bfs(root);
    }
    else if(choice == 5){
        int key;
        cout<<"enter the key to search:"<<endl;
        cin>>key;
        int k = search(root,key);
        if(k == -1)cout<<"element not found in the tree:"<<endl;
        else{
            cout<<"element found in the tree"<<endl;
        }
    }
    else{
        cout<<"you have given wrong choice so enter proper input:"<<endl;
    }
    



    return 0;
}