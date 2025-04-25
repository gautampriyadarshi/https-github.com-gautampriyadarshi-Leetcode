class Solution {
    int Rec(int i, int j, vector<vector<int>> &grid)
    {
        if (i == 0 && j == 0)
            return grid[i][j];

        if (i < 0 || j < 0)
            return INT_MAX;

        int up = grid[i][j] + Rec(i - 1, j, grid);
        int left = grid[i][j] + Rec(i, j - 1, grid);

        return min(up, left);
    }

    int Mem(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return grid[i][j];

        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = grid[i][j] + Rec(i - 1, j, grid);
        int left = grid[i][j] + Rec(i, j - 1, grid);

        return dp[i][j] = min(up, left);
    }

    int Tab(int m, int n, vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                        up += dp[i - 1][j];
                    else
                        up = INT_MAX;

                    int left = grid[i][j];
                    if (j > 0)
                        left += dp[i][j - 1];
                    else
                        left = INT_MAX;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        // Recursion:
        // return Rec(m-1, n-1, grid);

        // Memoization:
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return Mem(m-1, n-1, grid, dp);

        // Tabulation:
        // return Tab(m-1, n-1, grid);

        // Space Optimization:
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = grid[i][j];
                else
                {
                    int up = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up = INT_MAX;

                    int left = grid[i][j];
                    if (j > 0)
                        left += curr[j - 1];
                    else
                        left = INT_MAX;

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};