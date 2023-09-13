// find next node in same level for give node in a binary tree

#include <iostream>
#include <list>
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

// Function to find the next node of a given node in the same level
// in a given binary tree
Node *findRightNode(Node *root, Node *node)
{
    // return null if a tree is empty
    if (root == nullptr)
    {
        return nullptr;
    }

    // create an empty queue and enqueue the root node
    list<Node *> queue;
    queue.push_back(root);

    // pointer to store the current node
    Node *front = nullptr;

    // loop till queue is empty
    while (!queue.empty())
    {
        // calculate the total number of nodes at the current level
        int size = queue.size();

        // process every node of the current level and enqueue their
        // non-empty left and right child
        while (size--)
        {
            front = queue.front();
            queue.pop_front();

            // if the desired node is found, return its next right node
            if (front == node)
            {
                // if the next right node doesn't exist, return null
                if (size == 0)
                {
                    return nullptr;
                }

                return queue.front();
            }

            if (front->left)
            {
                queue.push_back(front->left);
            }

            if (front->right)
            {
                queue.push_back(front->right);
            }
        }
    }

    return nullptr;
}

int main()
{
    /* Construct the following tree
              1
            /  \
           /    \
          2      3
         / \      \
        4   5      6
                  / \
                 7   8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    Node *right = findRightNode(root, root->left->right);

    if (right)
    {
        cout << "Right node is " << right->data;
    }
    else
    {
        cout << "Right node doesn't exist";
    }

    return 0;
}