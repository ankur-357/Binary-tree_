// right view of tree

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<int> RightView(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    if (root == NULL)
        return ans;
    while (1)
    {
        int size = q.size();
        if (size == 0)
        {
            return ans;
        }
        int data = 0;
        while (size > 0)
        {
            Node *temp = q.front();
            q.pop();
            data = temp->data;

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            size--;
        }
        ans.push_back(data);
    }
    return ans;
}

vector<int> left(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> umap;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        Node *node = temp.first;
        int hd = temp.second;
        if (umap.find(hd) == umap.end())
        {
            umap[hd] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, hd + 1});
        }
        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }
    for (auto x : umap)
    {
        ans.push_back(x.second);
    }
    return ans;
}

class Solution
{
public:
    void recursion(Node *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;
        if (res.size() == level)   res.push_back(root->data);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }

    vector<int> rightSideView(Node *root)
    {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
int main()
{
}