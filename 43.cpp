// Serialize Binary Tree
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

// Encodes a tree to a single string.
// Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return {};
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
            ans.push_back(-1);
        else
            ans.push_back(curr->data);
        if (curr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return ans;
}

int main()
{
    // Example usage:
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> serializedTree = serialize(root);

    cout << "Serialized Tree: ";
    for (int val : serializedTree)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}