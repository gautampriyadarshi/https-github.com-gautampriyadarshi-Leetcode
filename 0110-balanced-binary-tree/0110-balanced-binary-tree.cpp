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
    int getHeight(TreeNode* root) 
    {
        if (!root) 
            return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
            return true;
        
        int left  = getHeight(root->left );
        int right = getHeight(root->right);

        if(abs(right - left) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        
        return false;
    }
};