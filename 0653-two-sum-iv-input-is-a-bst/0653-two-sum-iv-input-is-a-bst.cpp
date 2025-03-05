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
        
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
public:
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> vec;
        inorder(root, vec);

        for(int i = 0; i < vec.size()-1; i++)
        {
            for(int j = i+1; j < vec.size(); j++)
            {
                if(vec[i] + vec[j] == k)
                    return true;
            }
        }
        return false;
    }
};