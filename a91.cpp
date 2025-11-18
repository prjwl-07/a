#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

// ---------------- CUSTOM QUEUE FOR BFS ----------------
class Queue {
    Node* arr[100];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool empty() {
        return front == -1;
    }

    void push(Node* x) {
        if (rear == 99) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    Node* pop() {
        if (empty()) return NULL;
        Node* x = arr[front];

        if (front == rear)
            front = rear = -1;
        else
            front++;

        return x;
    }
};

// -------------- BST CLASS --------------------
class BST {
public:
    Node* insert(Node* root, int val) {
        if (root == NULL) return new Node(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    // ---------------- Traversals ----------------
    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // ---------------- BFS using custom queue ----------------
    void BFS(Node* root) {
        if (!root) return;

        Queue q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.pop();
            cout << curr->data << " ";

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    // ---------------- DFS (use preorder) ----------------
    void DFS(Node* root) {
        preorder(root);
    }

    // -------- longest path (height) ----------
    int height(Node* root) {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + (lh > rh ? lh : rh);
    }

    // -------- find minimum value -------------
    int findMin(Node* root) {
        while (root->left != NULL)
            root = root->left;
        return root->data;
    }

    // ---------- mirror tree (swap pointers) -----------
    void mirror(Node* root) {
        if (!root) return;

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        mirror(root->left);
        mirror(root->right);
    }

    // --------- search value ------------
    bool search(Node* root, int val) {
        if (!root) return false;
        if (val == root->data) return true;
        if (val < root->data) return search(root->left, val);
        return search(root->right, val);
    }
};

// -------------- MAIN PROGRAM -------------------
int main() {
    BST t;
    Node* root = NULL;

    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = t.insert(root, x);
    }

    cout << "\nPreorder: ";
    t.preorder(root);

    cout << "\nInorder: ";
    t.inorder(root);

    cout << "\nPostorder: ";
    t.postorder(root);

    cout << "\nBFS: ";
    t.BFS(root);

    cout << "\nDFS: ";
    t.DFS(root);

    cout << "\nLongest path length: " << t.height(root);

    cout << "\nMinimum value: " << t.findMin(root);

    cout << "\nMirroring tree...\n";
    t.mirror(root);

    cout << "Inorder after mirror: ";
    t.inorder(root);

    cout << "\nSearch value: ";
    int key;
    cin >> key;

    if (t.search(root, key))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
