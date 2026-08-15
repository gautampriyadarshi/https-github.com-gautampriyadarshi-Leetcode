// Gemini: https://gemini.google.com/u/1/app/4ddd2a9f22eddd2f
// Go to above link to understand the whole thought process, (new for me).

// Time Complexity: O(N*32) ≈ O(N).
// Space Complexity: O(N*32) ≈ O(N). 

// Define the Trie Node
struct TrieNode {
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a number into the Trie in binary format
    void insert(int num) {
        TrieNode* node = root;
        // Start from the most significant bit (31) down to 0
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; // Get the i-th bit
            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    // Find the maximum XOR for a given number
    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit; // The bit we WANT to find
            
            // If the opposite bit exists, take it to maximize XOR
            if (node->children[oppositeBit] != nullptr) {
                // Set the i-th bit of maxXor to 1
                maxXor = maxXor | (1 << i); 
                node = node->children[oppositeBit];
            } else {
                // Otherwise, we must take the same bit path
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxi = 0;
        
        // 1. Insert all numbers into the Trie
        for (int num : nums) {
            trie.insert(num);
        }
        
        // 2. Find the max XOR for each number
        for (int num : nums) {
            maxi = max(maxi, trie.getMaxXor(num));
        }
        
        return maxi;
    }
};