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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root) 
            return NULL;
        
        // Stage 1: Search for the node to remove
        if (key < root->val) {
            // Key is smaller, search in the left subtree
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            // Key is larger, search in the right subtree
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Stage 2: Node found! Now delete it.
            
            // Case 1 & 2: Node has 0 or 1 child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root; // Prevent memory leaks
                return temp; // Return the right child (could be null if 0 children)
            } 
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root; 
                return temp; // Return the left child
            }
            
            // Case 3: Node has 2 children
            // Find the In-order Successor (minimum value in the right subtree)
            TreeNode* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            
            // Replace the current node's value with the successor's value
            root->val = successor->val;
            
            // Delete the original successor node from the right subtree
            root->right = deleteNode(root->right, successor->val);
        }
        
        // Return the updated root of the tree/subtree
        return root;
    }
};