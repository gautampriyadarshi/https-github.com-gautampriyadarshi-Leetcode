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
    void preorder(TreeNode* root, vector<TreeNode*> &ans)
    {
        if(!root)
            return;

        ans.push_back(root);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:
    void flatten(TreeNode* root) 
    {
        vector<TreeNode*> ans;
        preorder(root, ans);

        TreeNode* temp = root;
        for(int i = 1; i < ans.size(); i++)
        {
            temp->left = NULL;
            temp->right = ans[i];
            temp = temp->right;
        }
    }
};