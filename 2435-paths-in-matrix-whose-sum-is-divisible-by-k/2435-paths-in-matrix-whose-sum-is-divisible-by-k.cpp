#define MOD 1000000007;
class Solution {
    int rec(int i, int j, int m, int n, vector<vector<int>>& grid, int k, 
            int currentSum)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        
        currentSum += grid[i][j];
        if(i == m-1 && j == n-1)
            return (currentSum % k == 0) ? 1 : 0;
        
        int right = rec(i, j+1, m, n, grid, k, currentSum);
        int down = rec(i+1, j, m, n, grid, k, currentSum);

        return (right + down) % MOD;
    }

    int mem(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int k, int currentSum)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        
        currentSum += grid[i][j];
        if(i == m-1 && j == n-1)
            return (currentSum % k == 0) ? 1 : 0;
        
        if(dp[i][j][currentSum % k] != -1)
            return dp[i][j][currentSum % k];
        
        int right = mem(i, j+1, m, n, grid, dp, k, currentSum);
        int down  = mem(i+1, j, m, n, grid, dp, k, currentSum);

        return dp[i][j][currentSum % k] = (right + down) % MOD;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();

        // Recursion:
        // return rec(0, 0, m, n, grid, k, 0);

        // Memoization:
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return mem(0, 0, m, n, grid, dp, k, 0);
    }
};