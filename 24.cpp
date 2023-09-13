// maximum width of Binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

int widthOfBinary(Node *root)
{
    if (!root)
        return 0;
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int curMin = q.front().second;
        int leftMost, rightMost;
        for (int i = 0; i < size; i++)
        {
            int cur_id = q.front().second;
            Node *temp = q.front().first;
            q.pop();

            if (i == 0)
                leftMost = cur_id;
            if (i == size - 1)
                rightMost = cur_id;
            if (temp->left)
            {
                q.push({temp->left, cur_id * 2 + 1});
            }
            if (temp->right)
            {
                q.push({temp->right, cur_id * 2 + 2});
            }
        }
        ans = max(ans, rightMost - leftMost + 1);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    int maxWidth = widthOfBinary(root);
    cout << "Maximum Width of Binary Tree: " << maxWidth << endl;

    return 0;
}
