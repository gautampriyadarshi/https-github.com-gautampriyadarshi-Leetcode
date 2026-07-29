class Solution {
    int Rec(int i, int j, string s, string t) 
    { 
        if(j < 0) 
            return 1; // If we have traversed the entire string t, it means we have found a valid subsequence of s that matches t, so we return 1.

        if(i < 0) 
            return 0; // If we have traversed the entire string s and haven't found a valid subsequence of s that matches t, we return 0.

        if(s[i] == t[j]) 
            return Rec(i-1, j-1, s, t) + Rec(i-1, j, s, t); // If the characters at the current indices of s and t match, we have two options: either include the character in the subsequence or exclude it. We add the results of both options.
        
        return Rec(i-1, j, s, t); 
    }

    int Mem(int i, int j, string &s, string &t, vector<vector<int>> &dp) 
    { 
        if(j < 0) 
            return 1; 

        if(i < 0) 
            return 0; 
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j]) 
            return dp[i][j] = Mem(i-1, j-1, s, t, dp) + Mem(i-1, j, s, t, dp); 
        
        return dp[i][j] = Mem(i-1, j, s, t, dp); 
    }
public:
    int numDistinct(string s, string t) 
    {
        int n = s.size(), m = t.size();

        // Recursion:
        // return Rec(n-1, m-1, s, t);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return Mem(n-1, m-1, s, t, dp);
    }
};