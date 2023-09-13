// Invert a Binary Tree

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *invertTree(Node *root)
{
    // Base Case
    if (root == NULL)
        return NULL;

    // Recursively invert the left and right subtrees
    Node *leftSubtree = invertTree(root->left);
    Node *rightSubtree = invertTree(root->right);

    // Swap the left and right subtrees
    root->left = rightSubtree;
    root->right = leftSubtree;

    return root; // Return the root of the inverted tree
}