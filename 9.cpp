// Balancing  of tree
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
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return 1;
    }
    return 0;
}
int main()
{
    /*
             1
           /   \
         3       6
        /       / \
      7        8    23
       \            /
         11        17
    */
}