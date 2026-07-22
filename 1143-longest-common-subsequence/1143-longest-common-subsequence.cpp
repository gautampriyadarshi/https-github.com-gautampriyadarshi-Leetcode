class Solution {
    int Rec(int i, int j, string &s, string &t)
    {
        if(i < 0 || j < 0)
            return 0;
        
        if(s[i] == t[j])
            return 1 + Rec(i-1, j-1, s, t);
        
        return max(Rec(i-1, j, s, t), Rec(i, j-1, s, t));
    }

    int Mem(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = 1 + Mem(i - 1, j - 1, s, t, dp);

        return dp[i][j] = max(Mem(i - 1, j, s, t, dp), Mem(i, j - 1, s, t, dp));
    }
public:
    int longestCommonSubsequence(string s, string t) 
    {
        int n = s.size(), m = t.size();

        // Recursion:
        // return Rec(n - 1, m - 1, s, t);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return Mem(n - 1, m - 1, s, t, dp);
    }
};