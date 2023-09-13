// Morris preOrder Traversal of BT

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<int> preOrderTraversal(Node *root)
{
    vector<int> preOrder;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            preOrder.push_back(curr->data);
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
                preOrder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preOrder;
}