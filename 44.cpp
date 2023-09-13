// Deserialize Binary Tree

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &a)
{
    // Your code here
    if (a.size() == 0)
        return NULL;
    int index = 0;
    int curr = a[index];
    Node *root = new Node(curr);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        index++;
        curr = a[index];
        if (curr == -1)
            node->left = NULL;
        else
        {
            Node *left = new Node(curr);
            node->left = left;
            q.push(left);
        }
        index++;
        curr = a[index];
        if (curr == -1)
            node->right = NULL;
        else
        {
            Node *right = new Node(curr);
            node->right = right;
            q.push(right);
        }
    }
    return root;
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:
//     // Encodes a tree to a single string.
//     void dfs(TreeNode* curr,string& s){
//         if(!curr){
//             s.push_back('*');
//             return;
//         }
//         s.append(to_string(curr->val)+",");
//         dfs(curr->left,s);
//         dfs(curr->right,s);
//     }
    
//     string serialize(TreeNode* root) {
//         string s="";
//         dfs(root,s);
//         cout<<s;
//         return s;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode *decode(string& data){
//         if(data.size()==0)  return NULL;
//         if(data[0]=='*'){
//             data = data.substr(1);
//             return NULL;
//         }
//         int pos = 0;
//         string no="";
//         while(data[pos]!=',')
//             no += data[pos++];
        
//         TreeNode *curr = new TreeNode(stoi(no));
//         data = data.substr(pos+1);
//         curr->left = decode(data);
//         curr->right = decode(data);
//         return curr;
//     }
    
//     TreeNode* deserialize(string data) {
//         if(data.size()<=1)  return NULL;
//         return decode(data);
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));