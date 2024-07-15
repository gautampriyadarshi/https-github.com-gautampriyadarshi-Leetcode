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
    TreeNode* createBinaryTree(vector<vector<int>>& des) 
    {
        unordered_map <int, TreeNode*> mp;
        unordered_map <int, int> parent, child;
        
        for(int i = 0; i < des.size(); ++i)
        {
            if(mp.find(des[i][0]) == mp.end())
            {
                // Entry not found in map so we will create the entry.
                TreeNode* nd = new TreeNode(des[i][0]);
                mp[des[i][0]] = nd;
            }

            if(mp.find(des[i][1]) == mp.end())
            {
                TreeNode* nd = new TreeNode(des[i][1]);
                mp[des[i][1]] = nd;
            }

            if(des[i][2])
                mp[des[i][0]]->left = mp[des[i][1]];
            
            else
                mp[des[i][0]]->right = mp[des[i][1]];

            parent[des[i][0]]++;
            child[des[i][1]]++;
        }

        TreeNode* ans;
        for(auto &x: mp)
        {
            if(parent.find(x.first) != parent.end() && child.find(x.first) == child.end())
            {
                ans = x.second;
                break;
            }
        }
        return ans;
    }
};