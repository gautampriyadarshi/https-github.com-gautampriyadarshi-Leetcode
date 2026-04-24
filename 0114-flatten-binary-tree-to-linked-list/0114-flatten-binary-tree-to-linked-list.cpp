/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void Preorder(TreeNode* root, vector<TreeNode*> &vec)
    {
        if(!root)
            return;

        vec.push_back(root);
        Preorder(root->left , vec);
        Preorder(root->right, vec);
    }
public:
    void flatten(TreeNode* root) 
    {
        if(!root)
            return;

        vector<TreeNode*> vec;
        Preorder(root, vec);

        root = vec[0];
        int i = 1;
        while(i < vec.size())
        {
            root->right = vec[i++];
            root->left = NULL;
            root = root->right;
        }
    }
};