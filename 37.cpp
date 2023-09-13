// Root to leaf Maximum path sum
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
void findSum(Node *root, int curr_sum, int max)
{
    if (!root)
        return;
    curr_sum += root->data;
    if (!root->left && !root->right && curr_sum > max)
    {
        max = curr_sum;
    }
    findSum(root->left, curr_sum, max);
    findSum(root->right, curr_sum, max);
}

int maxPathSum(Node *root)
{
    if (!root)
        return 0;
    int max = 0;
    int curr_sum = 0;
    findSum(root, curr_sum, max);
    return max;
}

int main()
{
    Node *root = new Node{10, new Node{2, nullptr, nullptr}, new Node{10, new Node{20, nullptr, nullptr}, new Node{1, nullptr, nullptr}}};
    cout << "Maximum path sum: " << maxPathSum(root) << endl;
    return 0;
}
