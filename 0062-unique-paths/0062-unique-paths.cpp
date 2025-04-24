class Solution {
    int Rec(int i, int j)
    {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        int up = Rec(i - 1, j);
        int left = Rec(i, j - 1);

        return up + left;
    }

    int Mem(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = Mem(i - 1, j, dp);
        int left = Mem(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int Tab(int m, int n)
    {
        int dp[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0, left = 0;

                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
public:
    int uniquePaths(int m, int n) 
    {
        // Recursion:
        // return Rec(m-1, n-1);

        // Memoization:
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return Mem(m-1, n-1, dp);

        // Tabulation:
        // return Tab(m-1, n-1);

        // Space Optimization:
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = 1;
                else
                {
                    int up = 0, left = 0;

                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = curr[j - 1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};