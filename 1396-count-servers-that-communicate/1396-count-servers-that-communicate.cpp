struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Combine hashes (bit-shifting to reduce collisions)
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int countTotal = 0;
        unordered_map<pair<int, int>, bool, pair_hash> mp;

        // Row:
        for(int i = 0; i < grid.size(); i++)
        {
            int count = 0;
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }

            if(count > 1)
            {
                countTotal += count;
                for(int j = grid[0].size()-1; j >= 0; j--)
                {
                    if(grid[i][j] == 1)
                        mp[{i,j}] = true;
                }
            }
        }

        // Column:
        for(int j = 0; j < grid[0].size(); j++)
        {
            int count = 0, countDouble = 0;
            for(int i = 0; i < grid.size(); i++)
            {
                if(grid[i][j] == 1)
                    count++;
                
                if(mp[{i,j}] == true)
                    countDouble++;
            }

            if(count > 1)
                countTotal += count - countDouble;
        }
        return countTotal;
    }
};