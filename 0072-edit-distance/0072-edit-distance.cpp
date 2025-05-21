class Solution {
    int Rec(int i, int j, string s1, string s2)
    {
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if (s1[i] == s2[j])
            return Rec(i - 1, j - 1, s1, s2);

        return 1 + min(Rec(i - 1, j, s1, s2), min(Rec(i, j - 1, s1, s2), Rec(i - 1, j - 1, s1, s2)));
    }

    int Mem(int i, int j, string s1, string s2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = Mem(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = 1 + min(Mem(i - 1, j, s1, s2, dp),
                                min(Mem(i, j - 1, s1, s2, dp), Mem(i - 1, j - 1, s1, s2, dp)));
    }

    int Tab(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        return dp[n][m];
    }

    int spaceOptimization(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1];

                else
                    curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int minDistance(string str1, string str2) 
    {
        int n = str1.size(), m = str2.size();

        // Recursion:
        // return Rec(n - 1, m - 1, str1, str2);

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return Mem(n - 1, m - 1, str1, str2, dp);

        // Tabulation:
        return Tab(str1, str2);

        // Space Optimization:
        // return spaceOptimization(str1, str2);
    }
};