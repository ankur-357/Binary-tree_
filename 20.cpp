// Iterative preorder, inorder and postorder

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> PreorderTraversal(Node *root)
{
    vector<int> preOrder;
    if (root == NULL)
        return preOrder;
    stack<Node *> st;
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        preOrder.push_back(temp->data);
        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
    }
    return preOrder;
}
vector<int> InorderTraversal(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    vector<int> inOrder;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            node = st.top();
            st.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }
    }
    return inOrder;
}
vector<int> PostOrderTraversal(Node *root)
{
    vector<int> postOrder;
    if (root == NULL)
        return postOrder;
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        Node *temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->left != NULL)
        {
            st1.push(temp->left);
        }
        if (temp->right != NULL)
        {
            st1.push(temp->right);
        }
    }
    while (!st2.empty())
    {
        postOrder.push_back(st2.top()->data);
        st2.pop();
    }

    return postOrder;
}

vector<int> postOrderTrav(Node *cur)
{
    vector<int> postOrder;
    if (cur == NULL)
        return postOrder;
    stack<Node *> st;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
                cur = temp;
        }
    }
    return postOrder;
}
vector<int> postOrderTraversal(Node *curr)
{
    vector<int> postOrder;
    if (curr == NULL)
    {
        return postOrder;
    }
    stack<Node *> st;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postOrder;
}

int main()
{
}