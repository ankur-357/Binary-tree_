// flatten bt to linked list
// 1. Using recursion
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
    Node *prev = NULL;

public:
    void flatten(Node *root)
    {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    void flattenIterative(Node *root)
    {
        if (root == NULL)
            return;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *curr = st.top();
            st.pop();
            if (curr->right != NULL)
            {
                st.push(curr->right);
            }
            if (curr->left != NULL)
            {
                st.push(curr->left);
            }
            if (!st.empty())
            {
                curr->right = st.top();
            }
            curr->left = NULL;
        }
    }
};
