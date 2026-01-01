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
    bool solve(TreeNode* root, int targetSum, int currentSum) 
    {
        if (!root) 
            return false;
        
        currentSum += root->val;

        if (root->left == NULL && root->right == NULL) 
        {
            if (currentSum == targetSum) 
                return true;
        }

        return ((solve(root->left, targetSum, currentSum)) || (solve(root->right, targetSum, currentSum)));
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return solve(root, targetSum, 0);
    }
};