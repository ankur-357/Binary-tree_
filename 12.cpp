// isSumTree of tree
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
int isSumTree(struct node *node)
{

    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 1;

    /* Get sum of nodes in left and right subtrees */
    int ls = isSumTree(node->left);
    int rs = isSumTree(node->right);

    /* if the node and both of its children satisfy the property return 1 else 0*/
    if ((node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right))
        return 1;
    else
        return 0;
}
int main()
{
}