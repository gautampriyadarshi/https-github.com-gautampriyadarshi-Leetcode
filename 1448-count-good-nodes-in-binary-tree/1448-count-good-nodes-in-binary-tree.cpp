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
    int dfs(TreeNode* node, int maxVal) 
    {
        if (!node) 
            return 0;

        int count = 0;
        if (node->val >= maxVal) {
            count = 1;
            maxVal = node->val;
        }

        count += dfs(node->left, maxVal);
        count += dfs(node->right, maxVal);

        return count;
    }

public:
    int goodNodes(TreeNode* root) 
    {
        if (!root) 
            return 0;
            
        return dfs(root, root->val);
    }
};