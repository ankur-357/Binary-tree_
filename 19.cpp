// LCA in Binary Tree

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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        return root;
    }
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node *p = root->left;
    Node *q = root->right;

    Node *lca = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;

    return 0;
}
