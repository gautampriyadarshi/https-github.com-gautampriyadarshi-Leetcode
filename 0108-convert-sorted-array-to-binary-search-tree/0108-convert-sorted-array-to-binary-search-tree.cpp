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
    TreeNode* solve(int lf, int rg, vector<int>& nums)
    {
        if(rg < lf)
            return NULL;
        
        int mid = lf + (rg - lf)/2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left  = solve(lf, mid-1, nums);
        node->right = solve(mid+1, rg, nums);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return NULL;

        return solve(0, nums.size()-1, nums);
    }
};