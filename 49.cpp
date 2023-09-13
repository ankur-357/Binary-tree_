// Find the diagonal sum of a binary tree

#include <iostream>
#include <unordered_map>
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

// Recursive function to perform preorder traversal on the tree and
// fill the map with the diagonal sum of elements
void diagonalSum(Node *root, int diagonal, auto &map)
{
    // base case: empty tree
    if (root == nullptr)
    {
        return;
    }

    // update the current diagonal with the node's value
    map[diagonal] += root->data;

    // recur for the left subtree by increasing diagonal by 1
    diagonalSum(root->left, diagonal + 1, map);

    // recur for the right subtree with the same diagonal
    diagonalSum(root->right, diagonal, map);
}

// Function to print the diagonal sum of a given binary tree
void diagonalSum(Node *root)
{
    // create an empty map to store the diagonal sum for every slope
    unordered_map<int, int> map;

    // traverse the tree in a preorder fashion and fill the map
    diagonalSum(root, 0, map);

    // traverse the map and print the diagonal sum
    for (int i = 0; i < map.size(); i++)
    {
        cout << map[i] << " ";
    }
}

int main()
{
    /* Construct the following tree
               1
             /  \
            /    \
           2      3
          /     /  \
         /     /    \
        4     5     6
             / \
            /   \
           7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    diagonalSum(root);

    return 0;
}
