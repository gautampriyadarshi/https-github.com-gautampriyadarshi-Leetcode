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

void solve(TreeNode *root, vector<int> &ans, int level)
{
    if(!root)
        return;
        
    // We entered to a new level:
    if(level == ans.size())
        ans.push_back(root->val);
        
    solve(root->right, ans, level+1);   
    solve(root->left, ans, level+1);

    // Since it is right view, so calling solve(root->right) before solve(root->left).
    // For left view, call solve(root->left) then solve(root->right).
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};