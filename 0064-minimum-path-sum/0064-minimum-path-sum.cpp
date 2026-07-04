class Solution {
    long long Rec(int i, int j, vector<vector<int>>& grid)
    {
        if(i == 0 && j == 0)
            return grid[i][j];

        if(i < 0 || j < 0)
            return INT_MAX;
        
        long long left = grid[i][j] + Rec(i, j-1, grid); 
        long long up   = grid[i][j] + Rec(i-1, j, grid);

        return min(left, up);
    }

    long long Mem(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return grid[i][j];

        if(i < 0 || j < 0)
            return INT_MAX;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long left = grid[i][j] + Mem(i, j-1, grid, dp); 
        long long up   = grid[i][j] + Mem(i-1, j, grid, dp);

        return dp[i][j] = min(left, up);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        // Recursion:
        // return Rec(m-1, n-1, grid);

        // Memoization:
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return Mem(m-1, n-1, grid, dp);
        
    }
};