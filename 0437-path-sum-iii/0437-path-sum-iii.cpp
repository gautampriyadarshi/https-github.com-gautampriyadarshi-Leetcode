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
    void solve(TreeNode *root, int k, int &count, vector<long long> &path)
    {
        if(!root)
            return;
        
        path.push_back(root->val);
        
        solve(root->left , k, count, path);
        solve(root->right, k, count, path);
        
        long long sum = 0;
        int size = path.size();
        
        for(int i = size-1; i >= 0; i--)
        {
            sum += path[i];
            if(sum == k)
                count++;
        }
        path.pop_back();
    }

public:
    int pathSum(TreeNode* root, int k) 
    {
        vector<long long>path;
        int count = 0;
        solve(root, k, count, path);
        return count;    
    }
};