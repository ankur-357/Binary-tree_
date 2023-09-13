// print root to given node path

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

bool getPath(Node *root, vector<int> &arr, int x)
{
    // if root is NULL there is no path
    if (!root)
        return false;
    // push the node's value in array
    arr.push_back(root->data);
    // if it is the required node return true
    if (root->data == x)
        return true;

    // else check whether the required node lies in the left subtree or right subtree of the current node
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }
    // required node does not lie either in the left or right subtree of the current node  thus remove current node's value from arr and then return false

    arr.pop_back();
    return false;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int x = 5; // Node whose path you want to find
    vector<int> path;

    if (getPath(root, path, x))
    {
        cout << "Path from root to " << x << " is: ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i < path.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    }
    else
    {
        cout << x << " not found in the tree." << endl;
    }

    return 0;
}