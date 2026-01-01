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
    void solve(TreeNode* root, int targetSum, int currentSum, vector<int> &help, vector<vector<int>> &ans) {
        if (!root) return;
        
        help.push_back(root->val);
        currentSum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (currentSum == targetSum) {
                ans.push_back(help); 
            }
        }

        solve(root->left, targetSum, currentSum, help, ans);
        solve(root->right, targetSum, currentSum, help, ans);

        // Backtrack: STRICTLY REQUIRED here because we passed by Reference
        help.pop_back(); 
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> help;
        solve(root, targetSum, 0, help, ans);
        return ans;
    }
};