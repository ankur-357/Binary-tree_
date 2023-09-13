// isSumTree of tree
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

pair<bool, int> isSumTree(Node *root)
{

    // base case
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> leftAns = isSumTree(root->left);
    pair<bool, int> rightAns = isSumTree(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condition = (root->data == (leftAns.second + rightAns.second));

    pair<bool, int> ans;

    if (isLeftSumTree && isRightSumTree && condition)
    {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else
    {
        ans.first = false;
        ans.second = root->data + leftSum + rightSum;
    }
}
int isSumTree(struct node *node)
{
}
int main()
{
}