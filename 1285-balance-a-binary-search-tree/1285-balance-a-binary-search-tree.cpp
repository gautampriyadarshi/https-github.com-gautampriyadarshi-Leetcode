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

    void inorder(TreeNode* root, vector<int> &vec)
    {
        if(root == NULL)
            return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }

    TreeNode* inorderToBST(int s, int e, vector<int> vec)
    {
        if(s > e)
            return NULL;

        int mid = (s+e)/2;
        TreeNode* newRoot = new TreeNode(vec[mid]);
        newRoot->left  = inorderToBST(s, mid-1, vec);
        newRoot->right = inorderToBST(mid+1, e, vec);
        return newRoot;
    }

public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> vec;
        inorder(root, vec);
        
        return inorderToBST(0, vec.size()-1, vec);
    }
};