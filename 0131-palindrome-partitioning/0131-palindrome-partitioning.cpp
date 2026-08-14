class Solution {
    bool isPalindrome(const string &s, int left, int right) 
    {
        while (left < right) 
        {
            if (s[left] != s[right]) 
                return false; 
            
            left++;
            right--;
        }
        return true;
    }

    void Rec(int ind, const string &s, vector<string> &currentPartition, vector<vector<string>> &result) 
    {
        // BASE CASE: We reached the end of the string.
        // This means the current sequence of cuts is fully valid.
        if (ind == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        for (int i = ind; i < s.length(); i++) 
        {
            // If the substring s[ind...i] is a palindrome...
            if (isPalindrome(s, ind, i)) 
            {
                // 1. TAKE: Extract the substring and add it to our current path
                // s.substr(starting_index, length)
                currentPartition.push_back(s.substr(ind, i - ind + 1));
                
                // 2. EXPLORE: Recursively partition the rest of the string
                Rec(i + 1, s, currentPartition, result);
                
                // 3. UNDO (Backtrack): Remove the substring to explore other potential cuts
                currentPartition.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> currentPartition;
        
        // Recursion:
        Rec(0, s, currentPartition, result);
        
        return result;
    }
};