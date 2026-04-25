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
    void inorder(TreeNode* root, TreeNode* &node, int val)
    {
        if(!root)
            return;
        
        if(root->val == val)
            node = root;

        inorder(root->left , node, val);
        inorder(root->right, node, val);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(!root)
            return NULL;
        
        TreeNode* node = NULL;
        inorder(root, node, val);

        return node;
    }
};