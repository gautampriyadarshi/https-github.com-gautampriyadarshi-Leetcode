class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> help(m*n + 1);
        int x, y;

        for(int i = 0; i < help.size(); i++)
        {
            help[i] = i;
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(help[grid[i][j]] == -1)
                    x = grid[i][j];
                
                help[grid[i][j]] = -1;
            }
        }

        for(int i = 1; i < help.size(); i++)
        {
            if(help[i] != -1)
            {
                y = help[i];
                break;
            }
        }

        return {x, y};
    }
};