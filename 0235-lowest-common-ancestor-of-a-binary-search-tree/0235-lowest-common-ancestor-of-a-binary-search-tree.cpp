/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
            return NULL;

        // If root->val is smaller than both p & q then go right.
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // If root->val is greater than both p & q then go left.
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};