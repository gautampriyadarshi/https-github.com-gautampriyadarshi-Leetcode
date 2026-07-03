#define MOD 2000000000;
class Solution {
    int Rec(int i, int j, vector<vector<int>>& matrix)
    {
        // In any case when matrix[i][j] == 1 then path is invalid
        if(i >= 0 && j >= 0 && matrix[i][j] == 1)
            return 0;

        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;
        
        int left = Rec(i, j-1, matrix);
        int up = Rec(i-1, j, matrix);

        return (left + up) % MOD;
    }

    int Mem(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp)
    {
        if(i >= 0 && j >= 0 && matrix[i][j] == 1)
            return 0;

        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = Mem(i, j-1, matrix, dp);
        int up = Mem(i-1, j, matrix, dp);

        return dp[i][j] = (left + up) % MOD;
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