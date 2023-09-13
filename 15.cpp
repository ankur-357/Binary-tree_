// reverse level order traversal

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<int> reverseOrder(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    stack<Node *> st;

    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        st.push(temp);
    }

    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        ans.push_back(node->data);
    }

    return ans;
}
int main()
{
}