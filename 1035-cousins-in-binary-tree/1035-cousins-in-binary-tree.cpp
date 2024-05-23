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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        unordered_map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            bool presentX = false, presentY = false;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL)
                {
                    q.push(node->left);

                    if(node->left->val == x)
                        mp[x] = node->val;
                    else if(node->left->val == y)
                        mp[y] = node->val;
                }
                
                if(node->right != NULL)
                {
                    q.push(node->right);
                    
                    if(node->right->val == x)
                        mp[x] = node->val;
                    else if(node->right->val == y)
                        mp[y] = node->val;
                }
                    

                if(node->val == x)
                    presentX = true;
                
                if(node->val == y)
                    presentY = true;
            }
            if(presentX && presentY)
            {
                if(mp[x] == mp[y])
                    return false;
                
                return true;
            }
            
            if((presentX && !presentY) || (!presentX && presentY))
                return false;
        }
        return false;
    }
};