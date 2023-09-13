// check for symmetrical Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bool isSymmetricUtil(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        return (root1->data == root2->data && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left));
    }
}

bool isSymmetric(struct Node *root)
{
    if (!root)
    {
        return true;
    }
    return isSymmetricUtil(root->left, root->right);
}

int main()
{
    // Create a symmetric binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root))
    {
        cout << "The binary tree is symmetric." << endl;
    }
    else
    {
        cout << "The binary tree is not symmetric." << endl;
    }

    return 0;
}
