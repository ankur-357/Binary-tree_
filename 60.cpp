// Truncate given binary tree to remove nodes which lie on a path having sum less than K

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

// The main function to truncate a given binary tree to remove nodes
// that lie on a path having a sum less than `k`
void trunc(Node *&curr, int k, int target)
{
    // base case: empty tree
    if (curr == nullptr)
    {
        return;
    }

    // update sum of nodes in the path from the root node to the current node
    target = target + (curr->data);

    // Recursively truncate left and right subtrees
    trunc(curr->left, k, target);
    trunc(curr->right, k, target);

    // Since we are doing postorder traversal, the subtree rooted at the current
    // node may be already truncated, and the current node is a leaf

    // if the current node is a leaf node and its path from the root node has a sum
    // less than the required sum, remove it
    if (target < k && isLeaf(curr))
    {
        // free the memory allocated to the current node
        delete (curr);

        // set current node to null (node is passed by reference)
        curr = nullptr;
    }
};

// Function to truncate a given binary tree to remove nodes which lie on
// a path having sum less than `k`
void truncate(Node *&root, int k)
{
    int target = 0;
    trunc(root, k, target);
}

int main()
{
    /* Construct the following tree
             6
           /   \
          /     \
         3       8
               /   \
              /     \
             4       2
           /   \      \
          /     \      \
         1       7      3
    */

    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node(2);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(3);

    int k = 20;
    truncate(root, k);
    inorder(root);

    return 0;
}