class Solution {
    int Rec(int i, int j, vector<vector<int>> &matrix)
    {
        if (j < 0 || j >= matrix[0].size())
            return INT_MAX;

        if (i == 0)
            return matrix[0][j];

        int up = matrix[i][j] + Rec(i - 1, j, matrix);
        int leftDiagonal = matrix[i][j] + Rec(i - 1, j - 1, matrix);
        int rightDiagonal = matrix[i][j] + Rec(i - 1, j + 1, matrix);
        return min(up, min(leftDiagonal, rightDiagonal));
    }

    int Mem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= matrix[0].size())
            return INT_MAX;

        if (i == 0)
            return matrix[0][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = matrix[i][j] + Mem(i - 1, j, matrix, dp);
        
        int leftDiagonal = matrix[i][j];
        if(j-1 >= 0)
            leftDiagonal += Mem(i - 1, j - 1, matrix, dp);
        else
            leftDiagonal = INT_MAX;

        int rightDiagonal = matrix[i][j];
        if(j+1 < matrix[0].size())
            rightDiagonal += Mem(i - 1, j + 1, matrix, dp);
        else
            rightDiagonal = INT_MAX;

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }

    int Tab(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0)
                    leftDiagonal += dp[i - 1][j - 1];
                else
                    leftDiagonal = INT_MAX;

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m)
                    rightDiagonal += dp[i - 1][j + 1];
                else
                    rightDiagonal = INT_MAX;

                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        for (int j = 0; j < m; j++)
        {
            // Tabulation:
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }

    int spaceOptimize(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), mini = INT_MAX;
        vector<int> prev(m, 0), curr(m, 0);

        for (int j = 0; j < m; j++)
        {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = matrix[i][j] + prev[j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0)
                    leftDiagonal += prev[j - 1];
                else
                    leftDiagonal = INT_MAX;

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m)
                    rightDiagonal += prev[j + 1];
                else
                    rightDiagonal = INT_MAX;

                curr[j] = min(up, min(leftDiagonal, rightDiagonal));
            }
            prev = curr;
        }

        for (int j = 0; j < m; j++)
        {
            mini = min(mini, prev[j]);
        }
        return mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size(), mini = INT_MAX;

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int j = 0; j < m; j++)
        {
            // Recursion:
            // mini = min(mini, Rec(n - 1, j, matrix));

            // Memoization:
            // mini = min(mini, Mem(n - 1, j, matrix, dp));
        }
        // return mini;

        // Tabulation:
        return Tab(matrix);

        // Space Optimization:
        // return spaceOptimize(matrix);
    }
};