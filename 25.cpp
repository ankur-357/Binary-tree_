// children sum property in BT

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
void reOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }
    if (child < root->data)
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }
    reOrder(root->left);
    reOrder(root->right);
    int total = 0;
    if (root->left)
    {
        total += root->left->data;
    }
    if (root->right)
    {
        total += root->right->data;
    }
    if (root->left || root->right)
    {
        root->data = total;
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    cout << "Original Tree:" << endl;
    cout << "   10" << endl;
    cout << "  /  \\" << endl;
    cout << "  8   2" << endl;
    cout << " / \\  /" << endl;
    cout << " 3  5" << endl;

    reOrder(root);

    cout << "After Applying Children Sum Property:" << endl;
    cout << "   20" << endl;
    cout << "  /  \\" << endl;
    cout << "  8   12" << endl;
    cout << " / \\" << endl;
    cout << " 3  9" << endl;

    return 0;
}
