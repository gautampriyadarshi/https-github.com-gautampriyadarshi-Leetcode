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

struct NodeInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};
class Solution {
    int globalMaxSum = 0;

    NodeInfo helper(TreeNode* root) 
    {
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        NodeInfo left = helper(root->left);
        NodeInfo right = helper(root->right);

        // Check BST conditions
        if (left.isBST && right.isBST && 
        root->val > left.maxVal && root->val < right.minVal) 
        {
            int currentSum = root->val + left.sum + right.sum;
            globalMaxSum = max(globalMaxSum, currentSum);
            
            return {true, 
                    min(root->val, left.minVal), 
                    max(root->val, right.maxVal), 
                    currentSum};
        }

        return {false, 0, 0, 0};
    }
public:
    int maxSumBST(TreeNode* root) 
    {
        globalMaxSum = 0; 
        helper(root);
        return globalMaxSum;
    }
};