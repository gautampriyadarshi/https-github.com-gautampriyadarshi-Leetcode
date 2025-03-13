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
    int solve(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        
        int leftSum  = solve(root->left , ans);
        int rightSum = solve(root->right, ans);

        int temp = max(max(leftSum, rightSum) + root->val, root->val);
        int res  = max(temp, leftSum + rightSum + root->val);
        ans = max(ans, res);
        return temp;
    }
public:
    int maxPathSum(TreeNode* root)
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};