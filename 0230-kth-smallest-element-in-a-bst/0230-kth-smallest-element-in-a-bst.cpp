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
    void solve(TreeNode* root, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        if(!root)
            return;
        
        pq.push(root->val);
        solve(root->left, pq);
        solve(root->right, pq);
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        solve(root, pq);

        while(k > 1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};