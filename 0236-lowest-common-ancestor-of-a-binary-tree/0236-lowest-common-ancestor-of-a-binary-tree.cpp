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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) 
    {
        if(!root)
            return NULL;
        
        if(root == n1 || root == n2)
            return root;
            
        TreeNode* leftAns  = lowestCommonAncestor(root->left, n1, n2);
        TreeNode* rightAns = lowestCommonAncestor(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL)
            return root;
            
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
            
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
            
        return NULL;    
    }
};