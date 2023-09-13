// Find the vertical sum of a binary tree

#include <iostream>
#include <map>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root
void printVerticalSum(Node *root, int dist, auto &map)
{
    // base case: empty tree
    if (root == nullptr)
    {
        return;
    }

    // update the map
    map[dist] += root->data;

    // recur for the left subtree by decreasing horizontal distance by 1
    printVerticalSum(root->left, dist - 1, map);

    // recur for the right subtree by increasing horizontal distance by 1
    printVerticalSum(root->right, dist + 1, map);
}

// Function to print the vertical sum of a given binary tree
void printVerticalSum(Node *root)
{
    // create an empty map where
    // key —> relative horizontal distance of the node from the root node, and
    // value —> sum of all nodes present at the same horizontal distance
    map<int, int> map;

    // perform preorder traversal on the tree and fill the map
    printVerticalSum(root, 0, map);

    // traverse the map and print the vertical sum
    for (auto it : map)
    {
        cout << it.second << " ";
    }
}

int main()
{
    /* Construct the following tree
            1
          /   \
         /     \
        2       3
              /   \
             /     \
            5       6
          /   \
         /     \
        7       8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printVerticalSum(root);

    return 0;
}
