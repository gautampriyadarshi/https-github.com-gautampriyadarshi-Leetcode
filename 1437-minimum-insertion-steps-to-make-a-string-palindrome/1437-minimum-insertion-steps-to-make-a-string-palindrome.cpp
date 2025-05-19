class Solution {
    int Rec(int i, int j, string &s, string &t)
    {
        if (i < 0 || j < 0)
            return 0;

        if (s[i] == t[j])
            return 1 + Rec(i - 1, j - 1, s, t);

        return max(Rec(i - 1, j, s, t), Rec(i, j - 1, s, t));
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

    int Tab(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base Case by shifting the index:
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1]) // (__-1) due to shifting of index.
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int spaceOptimization(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base Case by shifting the index:
        for (int j = 0; j <= m; j++)
        {
            prev[j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1]) // (__-1) due to shifting of index.
                    curr[j] = 1 + prev[j - 1];

                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }

public:
    // Function made by me:
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size(), m = t.size();

        // Recursion:
        // return Rec(n - 1, m - 1, s, t);

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return Mem(n - 1, m - 1, s, t, dp);

        // Tabulation:
        return Tab(s, t);

        // Space Optimization:
        // return spaceOptimization(s, t);
    }

    // Given Function:
    int minInsertions(string s) 
    {
        return s.size() - longestPalindromeSubseq(s);
    }
};