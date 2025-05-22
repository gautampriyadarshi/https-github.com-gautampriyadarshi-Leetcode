class Solution {
    int Rec(int i, int j, string pattern, string text)
    {
        if(i < 0 && j < 0)
            return true;
        
        if(i < 0 && j >= 0)
            return false;
        
        if(j < 0 && i >= 0)
        {
            for(int ind = 0; ind <= i; ind++)
            {
                if(pattern[ind] != '*')
                    return false;
            }
            return true;
        }

        if(pattern[i] == text[j] || pattern[i] == '?')
            return Rec(i-1, j-1, pattern, text);
        
        if(pattern[i] == '*')
            return Rec(i-1, j, pattern, text) || Rec(i, j-1, pattern, text);
        
        return false;    
    }

    int Mem(int i, int j, string pattern, string text, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0)
            return true;
        
        if(i < 0 && j >= 0)
            return false;
        
        if(j < 0 && i >= 0)
        {
            for(int ind = 0; ind <= i; ind++)
            {
                if(pattern[ind] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(pattern[i] == text[j] || pattern[i] == '?')
            return dp[i][j] = Mem(i-1, j-1, pattern, text, dp);
        
        if(pattern[i] == '*')
            return dp[i][j] = Mem(i-1, j, pattern, text, dp) || Mem(i, j-1, pattern, text, dp);
        
        return false;    
    }

    int Tab(string s, string p)
    {
        int n = p.size(), m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Pattern can match empty string only if all previous characters are '*'
        for(int i = 1; i <= n; i++) {
            if(p[i-1] == '*')
                dp[i][0] = dp[i-1][0];
            else
                dp[i][0] = false;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
public:
    bool isMatch(string s, string p) 
    {
        int n = p.size(), m = s.size();

        // Recursion:
        // return Rec(n-1, m-1, p, s); // p = text, s = pattern

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return Mem(n-1, m-1, p, s, dp);

        // Tabulation:
        return Tab(s, p);
    }
};
