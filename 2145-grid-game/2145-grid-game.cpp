class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        long long top = 0, bot = 0, mini = LLONG_MAX;
        for(int i = 0; i < grid[0].size(); i++)
        {
            top += grid[0][i];
        }

        for(int i = 0; i < grid[0].size(); i++)
        {
            top -= grid[0][i];
            mini = min(mini, max(top, bot));
            bot += grid[1][i];
        }
        return mini;
    }
};