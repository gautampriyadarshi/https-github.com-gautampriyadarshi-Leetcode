class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int x = -1, y = -1;
        vector<int> vec;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                vec.push_back(grid[i][j]);
            }
        }

        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size()-1; i++)
        {
            if(vec[i] == vec[i+1])
                x = vec[i];
            
            if(abs(vec[i]-vec[i+1]) == 2)
                y = vec[i]+1;
        }

        if(y == -1)
            y = vec[vec.size()-1]+1;
        
        if(vec[0] != 1)
            y = 1;

        return {x,y};
    }
};