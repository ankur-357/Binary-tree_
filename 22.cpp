// check for identical binary tree

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

bool isIdenticalUtil(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        return (root1->data == root2->data && isIdenticalUtil(root1->left, root2->left) && isIdenticalUtil(root1->right, root2->right));
    }
}

bool isIdentical(Node *r1, Node *r2)
{
    return isIdenticalUtil(r1, r2);
}

int main()
{
    // Create two identical binary trees
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    if (isIdentical(root1, root2))
    {
        cout << "The binary trees are identical." << endl;
    }
    else
    {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}
