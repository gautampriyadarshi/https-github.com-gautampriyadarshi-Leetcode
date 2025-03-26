#include<bits/stdc++.h>
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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        int width = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty())
        {
            int size = q.size(), mini = q.front().second, first, last;
            for(int i = 0; i < size; i++)
            {
                int curr = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();

                if(!i) 
                    first = curr;

                if(i == size-1) 
                    last = curr;

                if(node->left) 
                    q.push({node->left, (long long)curr*2 + 1});

                if(node->right) 
                    q.push({node->right, (long long)curr*2 + 2});
            }
            width = max(width, last - first + 1);
        }
        return width;
    }
};