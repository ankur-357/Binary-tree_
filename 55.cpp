// convert binary tree to its mirror

#include <iostream>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Function to perform preorder traversal on a given binary tree
void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to convert a given binary tree into its mirror
void convertToMirror(Node *root)
{
    // base case: if the tree is empty
    if (root == nullptr)
    {
        return;
    }

    // convert left subtree
    convertToMirror(root->left);

    // convert right subtree
    convertToMirror(root->right);

    // swap left subtree with right subtree
    swap(root->left, root->right);
}

int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    convertToMirror(root);
    preorder(root);

    return 0;
}
