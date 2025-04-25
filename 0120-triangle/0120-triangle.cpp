class Solution {
    int Rec(int i, int j, vector<vector<int>> &triangle, int n)
    {
        if (i == n - 1)
            return triangle[n - 1][j];

        int down = triangle[i][j] + Rec(i + 1, j, triangle, n);
        int diagonal = triangle[i][j] + Rec(i + 1, j + 1, triangle, n);

        return min(down, diagonal);
    }

    int Mem(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {
        if (i == n - 1)
            return triangle[n - 1][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] + Mem(i + 1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + Mem(i + 1, j + 1, triangle, n, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int Tab(vector<vector<int>> &triangle, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        int n = triangle[m-1].size();

        // Recursion:
        // return Rec(0, 0, triangle, n);

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return Mem(0, 0, triangle, n, dp);

        // Tabulation:
        // return Tab(triangle, n);

        // Space Optimization:
        vector<int> front(n, 0), curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            front[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diagonal);
            }
            front = curr;
        }
        return front[0];
    }
};