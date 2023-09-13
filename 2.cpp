// vertical order traversal
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

vector<int> verticalOrder(node *root)
{

    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(10);
    root->left->left->right = newNode(5);
    root->left->left->right->right = newNode(6);
    root->right = newNode(3);
    root->right->left = newNode(9);
    root->right->right = newNode(10);

    vector<int> verticalTraversal;
    verticalTraversal = verticalOrder(root);

    cout << "The Vertical Traversal is : " << endl;
    for (auto vertical : verticalTraversal)
    {
        cout << vertical << " ";
        cout << endl;
    }
    return 0;
}