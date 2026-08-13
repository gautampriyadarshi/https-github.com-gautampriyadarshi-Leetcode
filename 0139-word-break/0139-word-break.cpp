class Solution {
    bool Rec(int ind, string &s, unordered_set<string> &wordSet) 
    {
        if (ind == s.length())
            return true;

        string currentWord = "";
        for (int i = ind; i < s.length(); i++) 
        {
            currentWord += s[i];
            
            // If the current prefix is a valid dictionary word...
            if (wordSet.find(currentWord) != wordSet.end()) 
            {
                // ...make a cut and recursively check the remainder of the string.
                // If the remainder can be segmented, the whole path is valid!
                if (Rec(i + 1, s, wordSet) == true)
                    return true; 
            }
        }
        return false;
    }

    bool Mem(int ind, string &s, unordered_set<string> &wordSet, vector<int> &dp) 
    {
        if (ind == s.length())
            return true;
        
        if(dp[ind] != -1)
            return dp[ind];

        string currentWord = "";
        for (int i = ind; i < s.length(); i++) 
        {
            currentWord += s[i];
            
            if (wordSet.find(currentWord) != wordSet.end()) 
            {
                if (Mem(i + 1, s, wordSet, dp) == true)
                    return dp[ind] = 1;     // Not dp[i] = 1
            }
        }
        return dp[ind] = 0;
    }

    bool Tab(string &s, unordered_set<string> &wordSet) 
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;  // Reaching the end of the string means success
        
        // Loop backwards from n-1 down to 0
        for (int ind = n - 1; ind >= 0; ind--) 
        {
            string currentWord = "";
            for (int i = ind; i < n; i++) 
            {
                currentWord += s[i];
                if (wordSet.find(currentWord) != wordSet.end()) 
                {
                    if (dp[i + 1] == 1) {
                        dp[ind] = 1;
                        break; // We found a valid cut, no need to check further for this 'ind'
                    }
                }
            }
        }
        return dp[0];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();

        // Convert vector to unordered_set for O(1) average time lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // Recursion:
        // return Rec(0, s, wordSet);

        // Memoization:
        // vector<int> dp(n, -1);
        // return Mem(0, s, wordSet, dp);

        // Tabulation:
        return Tab(s, wordSet);
    }
};