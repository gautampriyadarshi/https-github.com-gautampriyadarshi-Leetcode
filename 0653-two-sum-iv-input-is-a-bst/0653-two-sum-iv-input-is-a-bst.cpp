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
        if(!root)
            return;
        
        inorder(root->left , vec);
        vec.push_back( root->val);
        inorder(root->right, vec);
    }
public:
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root)
            return false;
        
        vector<int> vec;
        inorder(root, vec);

        map<int, bool> mp;
        for(int i = 0; i < vec.size(); i++)
        {
            if(mp[k-vec[i]])
                return true;

            mp[vec[i]] = true;
        }

        return false;
    }
};