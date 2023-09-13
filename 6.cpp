// height of tree

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return max(leftH, rightH) + 1;
}
int main()
{
}