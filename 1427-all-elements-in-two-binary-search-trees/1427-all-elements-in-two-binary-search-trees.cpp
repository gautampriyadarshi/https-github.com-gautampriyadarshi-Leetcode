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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1 && !root2)
            return {};

        vector<int> ans;

        if(root1 != NULL)
        {
            queue<TreeNode*> q1;
            q1.push(root1);
            
            while(!q1.empty())
            {
                int size = q1.size();
                for(int i = 0; i < size; i++)
                {
                    TreeNode* node = q1.front();
                    q1.pop();

                    if(node->left != NULL)
                        q1.push(node->left);
                    
                    if(node->right != NULL)
                        q1.push(node->right);
                    
                    ans.push_back(node->val);
                }
            }
        }

        if(root2 != NULL)
        {
            queue<TreeNode*> q2;
            q2.push(root2);
            
            while(!q2.empty())
            {
                int size = q2.size();
                for(int i = 0; i < size; i++)
                {
                    TreeNode* node = q2.front();
                    q2.pop();

                    if(node->left != NULL)
                        q2.push(node->left);
                    
                    if(node->right != NULL)
                        q2.push(node->right);
                    
                    ans.push_back(node->val);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};