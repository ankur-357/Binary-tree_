// Diameter of tree
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
int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
}
int main()
{
}