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
public:
    int maxLevelSum(TreeNode* root) 
    {
        int maxi = INT_MIN, ans = -1, level = 0, sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            level++;
            for(int i = 0; i < sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
                
                sum += node->val;
            }

            if(sum > maxi)
            {
                maxi = max(maxi, sum);
                ans = level;
            }

            sum = 0;
        }
        return ans;
    }
};