#define MOD 2000000000;
class Solution {
    int Rec(int i, int j, vector<vector<int>> &matrix)
    {
        if (i >= 0 && j >= 0 && matrix[i][j] == 1) // Blockage represented by 1
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        int up = Rec(i - 1, j, matrix);
        int left = Rec(i, j - 1, matrix);

        return (up + left) % MOD;
    }

    int Mem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && matrix[i][j] == 1) // Blockage represented by 1
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = Mem(i - 1, j, matrix, dp);
        int left = Mem(i, j - 1, matrix, dp);

        return dp[i][j] = (up + left) % MOD;
    }

    int Tab(int m, int n, vector<vector<int>> &matrix)
    {
        int dp[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1) // Blockage represented by 1
                    dp[i][j] = 0;

                else if (i == 0 && j == 0)
                    dp[i][j] = 1;

                else
                {
                    int up = 0, left = 0;

                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = (up + left) % MOD;
                }
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();

        // Recursion:
        // return Rec(m-1, n-1, matrix);

        // Memoization:
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return Mem(m-1, n-1, matrix, dp);

        // Tabulation:
        // return Tab(m-1, n-1, matrix);
    }
};