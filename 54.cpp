// Print  cousins of given node in a binary tree

#include <iostream>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Function to find the level of the given node `x`
void findLevel(Node *root, Node *x, int index, int &level)
{
    // return if the tree is empty or level is already found
    if (root == nullptr || level)
    {
        return;
    }

    // if the given node is found, update its level
    if (root == x)
    {
        level = index;
    }

    // recur for the left and right subtree
    findLevel(root->left, x, index + 1, level);
    findLevel(root->right, x, index + 1, level);
}

void printLevel(Node *root, Node *node, int level)
{
    // base case
    if (root == nullptr)
    {
        return;
    }

    // print cousins
    if (level == 1)
    {
        cout << root->key << " ";
        return;
    }

    // recur for the left and right subtree if the given node
    // is not a child of the root
    if (!(root->left && root->left == node || root->right && root->right == node))
    {
        printLevel(root->left, node, level - 1);
        printLevel(root->right, node, level - 1);
    }
}

// Function to print all cousins of a given node
void printAllCousins(Node *root, Node *node)
{
    // base case
    if (root == nullptr || root == node)
    {
        return;
    }

    int level = 0;

    // find the level of the given node
    findLevel(root, node, 1, level);

    // print all cousins of a given node using its level number
    printLevel(root, node, level);
}

int main()
{
    /* Construct the following tree
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printAllCousins(root, root->right->left);

    return 0;
}