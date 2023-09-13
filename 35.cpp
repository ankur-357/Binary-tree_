// Root to Leaf path in BT
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
void pathUtil(Node *root, vector<vector<int>> &v, vector<int> &curr_path)
{
    if (!root)
        return;
    curr_path.push_back(root->data);
    if (!root->left && !root->right)
        v.push_back(curr_path);
    pathUtil(root->left, v, curr_path);
    pathUtil(root->right, v, curr_path);
    curr_path.pop_back();
}
vector<vector<int>> paths(Node *root)
{
    vector<vector<int>> v;
    vector<int> curr_path;
    pathUtil(root, v, curr_path);
    return v;
}