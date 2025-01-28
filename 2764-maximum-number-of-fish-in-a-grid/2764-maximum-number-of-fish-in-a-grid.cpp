class Solution {
    int solve(vector<vector<int>>& grid, int row, int col, int i, int j)
    {
        if(i >= row || j >= col || i < 0 || j < 0 || grid[i][j] == 0 || grid[i][j] == -1)
            return 0;
        
        int ans = grid[i][j];
        grid[i][j] = -1;

        ans += solve(grid, row, col, i+1, j) + solve(grid, row, col, i-1, j) +
                solve(grid, row, col, i, j-1) + solve(grid, row, col, i, j+1);
        
        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int ans = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                ans = max(ans, solve(grid, row, col, i, j));
            }
        }
        return ans;
    }
};