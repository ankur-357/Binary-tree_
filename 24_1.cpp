// vertical width of binary tree

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

void verticalWidthUtil(Node *root, map<int, int> &verticalLines, int line)
{
    if (root == nullptr)
        return;

    // Recursively traverse the left subtree, decrementing the vertical line by 1
    verticalWidthUtil(root->left, verticalLines, line - 1);

    // Increment the count of nodes at this vertical line
    verticalLines[line]++;

    // Recursively traverse the right subtree, incrementing the vertical line by 1
    verticalWidthUtil(root->right, verticalLines, line + 1);
}

int verticalWidth(Node *root)
{
    if (root == nullptr)
        return 0;

    // Use a map to store the count of nodes at each vertical line
    map<int, int> verticalLines;

    // Start the traversal from the root with line 0
    verticalWidthUtil(root, verticalLines, 0);

    // Calculate the maximum count of nodes in any vertical line
    int maxWidth = 0;
    for (auto &pair : verticalLines)
    {
        maxWidth = max(maxWidth, pair.second);
    }

    return maxWidth;
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

    int verticalWidthValue = verticalWidth(root);
    cout << "Vertical Width of Binary Tree: " << verticalWidthValue << endl;

    return 0;
}
