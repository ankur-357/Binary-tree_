// zigzag traversal

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<vector<int>> zigzag(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);
    int count = 0;
    if (root == NULL)
    {
        return ans;
    }
    while (1)
    {
        int size = q.size();
        if (size == 0)
        {
            return ans;
        }
        count++;
        vector<int> data;
        while (size > 0)
        {
            Node *temp = q.front();
            q.pop();

            data.push_back(temp->data);

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
        if (count % 2 == 0)
        {
            reverse(data.begin(), data.end());
            ans.push_back(data);
        }
    }
    return ans;
}
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }
    queue<Node *> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = nodesQueue.front();
            nodesQueue.pop();

            // first position to fill node's value
            int index = (leftToRight) ? i : (size - i - 1);

            row[index] = node->data;
            if (node->left != NULL)
            {
                nodesQueue.push(node->left);
            }
            if (node->right != NULL)
            {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
int main()
{
}