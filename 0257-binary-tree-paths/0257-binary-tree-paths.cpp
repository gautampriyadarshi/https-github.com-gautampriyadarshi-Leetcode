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
    void solve(TreeNode* root, vector<string> &ans, string help)
    {
        if(!root)
            return;
        
        if(help.empty())
            help = help + to_string(root->val);
        else
            help = help + "->" + to_string(root->val);

        if(!root->left && !root->right)
            ans.push_back(help);
        
        solve(root->left , ans, help);
        solve(root->right, ans, help);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        string help = "";
        solve(root, ans, help);
        return ans;
    }
};