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
        if (!root)
            return 0;

        int maxWidth = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});  // Push root node with index 0

        while (!q.empty()) 
        {
            int size = q.size();
            int minIndex = q.front().second;
            int first = 0, last = 0;    // To track first and last index

            for (int i = 0; i < size; i++) 
            {
                int currIndex = q.front().second - minIndex;

                TreeNode* node = q.front().first;
                q.pop();

                // Update the first index if it's the first node
                if (i == 0)
                    first = currIndex;

                // Update the last index if it's the last node
                if (i == size - 1)
                    last = currIndex;

                if (node->left)
                    q.push({node->left, (long long)2 * currIndex + 1});

                if (node->right)
                    q.push({node->right, (long long)2 * currIndex + 2});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }
};

// For every left node : width = (2 * parentIndex + 1)
// For every right node: width = (2 * parentIndex + 2)
// Width we are finding by calculating with (rightMostIndex - leftMostIndex + 1).