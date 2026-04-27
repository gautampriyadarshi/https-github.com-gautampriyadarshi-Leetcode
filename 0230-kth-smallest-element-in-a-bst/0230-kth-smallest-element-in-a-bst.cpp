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
        
        solve(root->left, pq);
        pq.push(root->val);     // Inorder traversal to get answer quickly.
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