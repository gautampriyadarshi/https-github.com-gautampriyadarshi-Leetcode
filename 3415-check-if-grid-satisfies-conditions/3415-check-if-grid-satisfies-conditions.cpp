class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) 
    {
        bool singleRow = true, singleCol = true;
        for(int i = 0; i < grid.size()-1; i++)
        {
            singleRow = false;
            for(int j = 0; j < grid[i].size()-1; j++)
            {
                singleCol = false;

                if(grid[i][j] != grid[i+1][j])
                    return false;
                
                if(grid[i][j] == grid[i][j+1])
                    return false;
            }
        }

        for(int i = grid.size()-1; i > 0; i--)
        {
            for(int j = grid[0].size()-1; j > 0; j--)
            {
                if(grid[i][j] != grid[i-1][j])
                    return false;
                
                if(grid[i][j] == grid[i][j-1])
                    return false;
            }
        }

        if(singleCol)
        {
            for(int i = 0; i < grid.size()-1; i++)
            {
                if(grid[i][0] != grid[i+1][0])
                    return false;
            }
        }

        if(singleRow)
        {
            for(int j = 0; j < grid[0].size()-1; j++)
            {
                if(grid[0][j] == grid[0][j+1])
                    return false;
            }
        }

        return  true;
    }
};