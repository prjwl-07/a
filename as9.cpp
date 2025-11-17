#include <iostream>
#include <queue>
using namespace std;

// -----------------------------
// Definition of Node class
// -----------------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node with data
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// --------------------------------------------------
// Function to insert a node into the Binary Search Tree
// --------------------------------------------------
Node* insert_node(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (val < root->data)
        root->left = insert_node(root->left, val);
    else
        root->right = insert_node(root->right, val);

    return root;
}

// --------------------------------------------------
// Function to create a BST from an array of integers
// --------------------------------------------------
Node* create_bst(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert_node(root, arr[i]);
    }
    return root;
}

// --------------------------------------------------
// Preorder Traversal (Root → Left → Right)
// --------------------------------------------------
void display_preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    display_preorder(root->left);
    display_preorder(root->right);
}

// --------------------------------------------------
// Inorder Traversal (Left → Root → Right)
// --------------------------------------------------
void display_inorder(Node* root) {
    if (root == NULL)
        return;

    display_inorder(root->left);
    cout << root->data << " ";
    display_inorder(root->right);
}

// --------------------------------------------------
// Postorder Traversal (Left → Right → Root)
// --------------------------------------------------
void display_postorder(Node* root) {
    if (root == NULL)
        return;

    display_postorder(root->left);
    display_postorder(root->right);
    cout << root->data << " ";
}

// --------------------------------------------------
// Breadth-First Search (Level Order Traversal)
// --------------------------------------------------
void display_BFS(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();
        cout << curr->data << " ";

        if (curr->left != NULL)
            Q.push(curr->left);
        if (curr->right != NULL)
            Q.push(curr->right);
    }
}

// --------------------------------------------------
// Function to swap left and right subtrees of every node
// --------------------------------------------------
void swap_sub_trees(Node* root) {
    if (root == NULL)
        return;

    swap(root->left, root->right);
    swap_sub_trees(root->left);
    swap_sub_trees(root->right);
}

// --------------------------------------------------
// Function to find the minimum value node in BST
// --------------------------------------------------
int find_min_node(Node* root) {
    if (root == NULL)
        return 0;

    Node* current = root;
    while (current->left != NULL)
        current = current->left;

    return current->data;
}

// --------------------------------------------------
// Function to calculate height of the tree
// --------------------------------------------------
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(leftheight, rightheight) + 1;
}

// --------------------------------------------------
// Function to search for a node in the BST
// --------------------------------------------------
int search_node(Node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return root->data;
    else if (root->data > key)
        return search_node(root->left, key);
    else
        return search_node(root->right, key);
}

// --------------------------------------------------
// Main function with menu-driven program
// --------------------------------------------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = create_bst(arr, n);

    int choice;
    do {
        cout << "\n---- Binary Search Tree Operations ----\n";
        cout << "1. Preorder traversal\n";
        cout << "2. Inorder traversal\n";
        cout << "3. Postorder traversal\n";
        cout << "4. Level order traversal\n";
        cout << "5. Swap subtrees\n";
        cout << "6. Find minimum node\n";
        cout << "7. Find height of tree\n";
        cout << "8. Search node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Preorder: ";
                display_preorder(root);
                cout << endl;
                break;

            case 2:
                cout << "Inorder: ";
                display_inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Postorder: ";
                display_postorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Level order: ";
                display_BFS(root);
                cout << endl;
                break;

            case 5:
                cout << "Subtrees swapped.\n";
                swap_sub_trees(root);
                break;

            case 6:
                cout << "Minimum node: " << find_min_node(root) << endl;
                break;

            case 7:
                cout << "Height of tree: " << height(root) << endl;
                break;

            case 8: {
                int val;
                cout << "Enter value to search: ";
                cin >> val;
                if (search_node(root, val))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
