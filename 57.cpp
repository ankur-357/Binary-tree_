// In-place convert given Binary tree to doubly linked list

#include <iostream>
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

// Helper function to print a given doubly linked list
void printDLL(Node *&head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Function to in-place convert a given binary tree into a doubly linked list
// by doing normal inorder traversal
void convert(Node *root, Node *&head)
{
    // base case: tree is empty
    if (root == nullptr)
    {
        return;
    }

    // recursively convert the left subtree first
    convert(root->left, head);
    root->left = nullptr;

    // store right child
    Node *right = root->right;

    // insert the current node at the beginning of a doubly linked list
    root->right = head;
    if (head != nullptr)
    {
        head->left = root;
    }

    head = root;

    // recursively convert the right subtree
    convert(right, head);
}

// Function to reverse a doubly-linked list
void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *current = head;

    while (current)
    {
        swap(current->left, current->right);
        prev = current;
        current = current->left;
    }

    if (prev != nullptr)
    {
        head = prev;
    }
}

// The main function to in-place convert a given binary tree into a
// doubly linked list
void convert(Node *root)
{
    // head of the doubly linked list
    Node *head = nullptr;

    // convert the above binary tree into doubly linked list
    convert(root, head);

    // reverse the linked list
    reverse(head);

    // print the list
    printDLL(head);
}

int main()
{
    /* Construct the following tree
              1
            /   \
           /     \
          2       3
         / \     / \
        4   5   6   7
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    convert(root);

    return 0;
}
