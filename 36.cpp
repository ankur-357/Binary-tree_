// Find root to leaf path sum in BT
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
void findSum(Node *root, int curr_sum, int sum, bool isFound)
{
    if (!root)
    {
        return;
    }
    curr_sum += root->data;
    if (!root->left && !root->right && curr_sum == sum)
    {
        isFound = true;
        findSum(root->left, curr_sum, sum, isFound);
        findSum(root->right, curr_sum, sum, isFound);
    }
}