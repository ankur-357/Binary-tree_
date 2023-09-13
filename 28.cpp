// count total nodes in complete Binary tree

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

void inOrder(Node *curr, int &count)
{
    if (curr == NULL)
    {
        return;
    }
    count++;
    inOrder(curr->left, count);
    inOrder(curr->right, count);
}

int findHeightLeft(Node *curr)
{
    int height = 0;
    while (curr)
    {
        height++;
        curr = curr->left;
    }
    return height;
}

int findHeightRight(Node *curr)
{
    int height = 0;
    while (curr)
    {
        height++;
        curr = curr->right;
    }
    return height;
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if (lh == rh)
    {
        return (1 << lh);
    }
    else
    {
        return countNodes(root->left) + countNodes(root->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int count = 0;
    inOrder(root, count);
    cout << "The number of nodes in the tree is: " << count << endl;
    return 0;
}
