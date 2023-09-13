// Convert given binary tree to full tree by removing half nodes
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

// Function to perform inorder traversal on the tree
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

// Function to check if a given node is a leaf node or not
bool isLeaf(Node *node)
{
    return (node->left == nullptr && node->right == nullptr);
}

// Function to convert a binary tree into a full tree by removing half nodes
Node *truncate(Node *root)
{
    // base case: empty tree
    if (root == nullptr)
    {
        return nullptr;
    }

    // recursively truncate the left subtree and subtree first
    root->left = truncate(root->left);
    root->right = truncate(root->right);

    // do nothing if the current node is a leaf node or has two children
    if ((root->left && root->right) || isLeaf(root))
    {
        return root;
    }

    // if the current node has exactly one child, delete it and replace
    // it with the child node
    Node *child = (root->left) ? root->left : root->right;
    delete root;
    return child;
}

int main()
{
    /* Construct the following tree
                 0
               /   \
              /     \
             1       2
            /       /
           /       /
          3       4
         /       / \
        /       /   \
       5       6     7
    */

    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->left = new Node(4);
    root->left->left->left = new Node(5);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    root = truncate(root);
    inorder(root);

    return 0;
}