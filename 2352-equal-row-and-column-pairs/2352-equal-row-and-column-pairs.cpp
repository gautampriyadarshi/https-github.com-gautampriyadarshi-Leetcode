class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int count = 0;
        vector<int> help;
        map<vector<int>, int> mp;

        // Adding vector of rows in set
        for(int i = 0; i < grid.size(); i++)
        {
            mp[grid[i]]++;
        }

        // Checking each column
        for(int j = 0; j < grid[0].size(); j++)
        {
            for(int i = 0; i < grid.size(); i++)
            {
                help.push_back(grid[i][j]);
            }

            if(mp.find(help) != mp.end())
                count += mp[help];
            
            help.clear();
        }
        return count;
    }
};