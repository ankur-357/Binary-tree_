// check for subtree in a BInary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right));
}

bool isSubtree(Node *root1, Node *root2)
{
    if (root2 == NULL)
        return true;
    if (root1 == NULL)
        return false;

    if (isIdentical(root1, root2))
        return true;

    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

int main()
{
    Node *root1 = new Node();
    root1->data = 5;
    root1->left = new Node();
    root1->left->data = 3;
    root1->right = new Node();
    root1->right->data = 8;
    root1->left->left = new Node();
    root1->left->left->data = 2;
    root1->left->right = new Node();
    root1->left->right->data = 4;

    Node *root2 = new Node();
    root2->data = 3;
    root2->left = new Node();
    root2->left->data = 2;
    root2->right = new Node();
    root2->right->data = 4;

    if (isSubtree(root1, root2))
        cout << "Tree 2 is a subtree of Tree 1." << endl;
    else
        cout << "Tree 2 is not a subtree of Tree 1." << endl;

    return 0;
}
