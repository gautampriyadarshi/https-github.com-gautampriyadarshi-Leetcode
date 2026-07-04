class Solution {
    int Rec(int i, int j, vector<vector<int>>& triangle, int m)
    {
        if(i == m-1)
            return triangle[m-1][j];
        
        int down     = triangle[i][j] + Rec(i+1, j  , triangle, m);
        int diagonal = triangle[i][j] + Rec(i+1, j+1, triangle, m);

        return min(down, diagonal);
    }

    int Mem(int i, int j, vector<vector<int>>& triangle, int m, vector<vector<int>> &dp)
    {
        if(i == m-1)
            return triangle[m-1][j];

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down     = triangle[i][j] + Mem(i+1, j  , triangle, m, dp);
        int diagonal = triangle[i][j] + Mem(i+1, j+1, triangle, m, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int Tab(vector<vector<int>>& triangle, int m)
    {
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        for(int i = m-2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int down     = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();

        // Recursion:
        // return Rec(0, 0, triangle, m);

        // Memoization:
        // vector<vector<int>> dp(m, vector<int>(m, -1));
        // return Mem(0, 0, triangle, m, dp);

        // Tabulation:
        return Tab(triangle, m);
    }
};