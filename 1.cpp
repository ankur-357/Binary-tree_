//top view
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q;
    map<int, int> mpp;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int hd = it.second;

        if (mpp.find(hd) == mpp.end())
            mpp[hd] = node->data;

        if (node->left != NULL)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right != NULL)
        {
            q.push({node->right, hd + 1});
        }
    }
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
int main()
{
}