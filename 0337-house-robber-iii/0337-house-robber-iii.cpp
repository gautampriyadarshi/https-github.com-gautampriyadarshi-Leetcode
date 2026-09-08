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
    unordered_map<TreeNode *, int> mp;
    int Rec(TreeNode* root)
    {
        if (!root)
            return 0;

        int val = 0;
        if (root->left)
            val += Rec(root->left->left) + Rec(root->left->right);

        if (root->right)
            val += Rec(root->right->left) + Rec(root->right->right);

        int notrob = Rec(root->left) + Rec(root->right);
        int rob = val + root->val;

        return max(notrob, rob);
    }

    int Mem(TreeNode* root)
    {
        if (!root)
            return 0;

        if (mp.find(root) != mp.end())
            return mp[root];

        mp[root] = -1;

        int x = Mem(root->left) + Mem(root->right);
        int y = root->val;

        if (root->left)
            y += Mem(root->left->left) + Mem(root->left->right);

        if (root->right != NULL)
            y += Mem(root->right->left) + Mem(root->right->right);

        mp[root] = max(x, y);
        
        return mp[root];
    }

    pair<int, int> solve(TreeNode* root) 
    {
        if (!root) 
            return {0, 0};

        // Post-order traversal (bottom-up)
        auto [leftRob, leftNotRob] = solve(root->left);
        auto [rightRob, rightNotRob] = solve(root->right);

        // Case 1: ROB current node
        // Cannot rob children; must take their "not rob" states
        int robCurr = root->val + leftNotRob + rightNotRob;

        // Case 2: DO NOT ROB current node
        // Free to rob or not rob children—take whichever yields more for each child
        int notRobCurr = max(leftRob, leftNotRob) + max(rightRob, rightNotRob);

        return {robCurr, notRobCurr};
    }
public:
    int rob(TreeNode* root) 
    {
        // Recursion:
        // return Rec(root);

        // Memoization:
        // return Mem(root);

        // Optimal Solution:
        auto [rob, notRob] = solve(root);
        return max(rob, notRob);
    }
};