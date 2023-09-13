// morris inorder traversal of BT

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> inOrderTraversal(Node *root)
{
    vector<int> inOrder;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inOrder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inOrder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inOrder;
}