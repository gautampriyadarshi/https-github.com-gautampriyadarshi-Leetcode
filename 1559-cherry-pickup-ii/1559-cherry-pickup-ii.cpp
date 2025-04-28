class Solution {
    int Rec(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
    {
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
            return INT_MIN;

        if (i == r - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        // explore all paths of alice and bob simultaneously
        int maxi = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int value = 0;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += Rec(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }

    int Mem(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,  vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
            return INT_MIN;

        if (i == r - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // explore all paths of alice and bob simultaneously
        int maxi = INT_MIN;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                int value = 0;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += Mem(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int Tab(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for(int j1 = 0; j1<m; j1++)
        {
            for(int j2 = 0; j2<m; j2++)
            {
                if(j1 == j2) dp[n-1][j1][j1] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i = n-2; i>=0; i--)
        {
            for(int j1 = 0; j1<m; j1++)
            {
                for(int j2 = 0; j2<m; j2++)
                {
                    int maximum = INT_MIN;
                    for(int k1 = -1; k1<=1; k1++)
                    {
                        int sum =0;
                        for(int k2 = -1; k2<=1; k2++)
                        {
                            if(j1 == j2)
                            {
                                sum = grid[i][j1];
                            }
                            else
                            {
                                sum = grid[i][j1] + grid[i][j2];
                            }
                            if(j1+k1 < 0 || j1+k1 >=m || j2+k2<0 || j2+k2 >=m)
                            {
                                sum += -1e9;
                            }
                            else
                            {
                                sum += dp[i+1][j1+k1][j2+k2];
                            }
                            maximum = max(maximum, sum);
                        }
                    }
                    dp[i][j1][j2] = maximum;  
                }
            }
        }
        return dp[0][0][m-1];
    }

public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r = grid.size(), c = grid[0].size();
        // Recursion:
        // return Rec(0, 0, c - 1, r, c, grid);

        // Memoization:
        // int dp[r][c][c]
        // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        // return Mem(0, 0, c - 1, r, c, grid, dp);

        // Tabulation:
        return Tab(r, c, grid);
    }
};