#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------
// Node structure for Binary Tree
//-------------------------------------------
struct Node {
    string name;
    Node* left;   // Left child
    Node* right;  // Right child

    Node(string n) {
        name = n;
        left = right = nullptr;
    }
};

//-------------------------------------------
// Function to display tree recursively
//-------------------------------------------
void display(Node* root, int level = 0) {
    if (root == nullptr)
        return;

    // Print indentation to show tree level
    for (int i = 0; i < level; i++)
        cout << "   ";

    cout << root->name << endl;

    // Recursively display left and right children
    display(root->left, level + 1);
    display(root->right, level + 1);
}

//-------------------------------------------
// Main function
//-------------------------------------------
int main() {
    // Creating a simple binary tree

    Node* root = new Node("Folder-01");

    // Left and right children of root
    root->left = new Node("Folder-A");
    root->right = new Node("Folder-B");

    // Children of Folder-A
    root->left->left = new Node("File-A1");
    root->left->right = new Node("File-A2");

    // Children of Folder-B
    root->right->left = new Node("File-B1");
    root->right->right = new Node("File-B2");

    // Display structure
    cout << "Folder Structure (Simple Binary Tree):\n";
    display(root);

    return 0;
}
