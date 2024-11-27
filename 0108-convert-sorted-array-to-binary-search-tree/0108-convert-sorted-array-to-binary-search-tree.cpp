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
    TreeNode* solve(int l, int r, vector<int>& nums)
    {
        if(r < l)
            return NULL;
        
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left  = solve(l, mid-1, nums);
        node->right = solve(mid+1, r, nums);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return solve(0, nums.size()-1, nums);
    }
};