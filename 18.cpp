// max path sum

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

int findMaxPathSum(Node *root, int &maxSum)
{
    if (root == nullptr)
    {
        return 0;
    }

    // Calculate the maximum path sum for the left and right subtrees
    int leftMaxPath = max(0, findMaxPathSum(root->left, maxSum));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxSum));

    // Calculate the maximum path sum including the current node
    int currentMaxPath = leftMaxPath + rightMaxPath + root->data;

    // Update the maximum path sum if the current path is greater
    maxSum = max(maxSum, currentMaxPath);
    cout << maxSum<< "*"<< endl;
    // Return the maximum path sum for the subtree rooted at the current node
    cout << max(leftMaxPath, rightMaxPath) + root->data << endl;
    return max(leftMaxPath, rightMaxPath) + root->data;
}

int maxPathSum(Node *root)
{
    int maxSum = INT_MIN;
    findMaxPathSum(root, maxSum);
    return maxSum;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    int ans = maxPathSum(root);
    cout << "Maximum Path Sum: " << ans << endl;
    /*
                    1
                  /   \
                2      7
               /         \
              3           8
               \        /
                4      9
               / \    / \
              5   6  8   11
        */
    return 0;
}
