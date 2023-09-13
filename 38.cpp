// k distance from root
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void kdistance(Node *root, int k, vector<int> &v)
{
    if (!root)
    {
        return;
    }
    if (k == 0)
    {
        v.push_back(root->data);
        return;
    }

    // Decrement k and explore the subtrees
    kdistance(root->left, k - 1, v);
    kdistance(root->right, k - 1, v);
}

int main()
{
    Node *root = new Node{1, new Node{2, new Node{4, nullptr, nullptr}, new Node{5, nullptr, nullptr}}, new Node{3, nullptr, nullptr}};
    vector<int> result;
    int k = 2;
    kdistance(root, k, result);

    cout << "Nodes at distance " << k << " from root: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
