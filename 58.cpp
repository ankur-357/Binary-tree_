// sink nodes containing zero to the bottom of the binary tree

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

// Function to perform inorder traversal on a given binary tree
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to sink root node having value 0 at the bottom of the tree.
// The left and right subtree (if any) of the root node are already sinked
void sink(Node *root)
{
    // base case: tree is empty
    if (root == nullptr)
    {
        return;
    }

    // if the left child exists and has a non-zero value
    if (root->left && root->left->data != 0)
    {
        // swap the current node data with its left child
        swap(root->data, root->left->data);

        // recur for the left subtree
        sink(root->left);
    }

    // if the right child exists and has a non-zero value
    else if (root->right && root->right->data != 0)
    {
        // swap the current node data with its right child
        swap(root->data, root->right->data);

        // recur for the right subtree
        sink(root->right);
    }
}

// The main function to sink nodes having zero value at the bottom
// of the binary tree
void sinkNodes(Node *&root)
{
    // base case: tree is empty
    if (root == nullptr)
    {
        return;
    }

    // fix left and right subtree first
    sinkNodes(root->left);
    sinkNodes(root->right);

    // sink the current node if it has a value of 0
    if (root->data == 0)
    {
        sink(root);
    }
}

int main()
{
    /* Construct the following tree
              0
            /   \
           /     \
          1       0
                /   \
               /     \
              0       2
            /   \
           /     \
          3       4
    */

    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(2);
    root->right->left->left = new Node(3);
    root->right->left->right = new Node(4);

    sinkNodes(root);
    inorder(root);

    return 0;
}