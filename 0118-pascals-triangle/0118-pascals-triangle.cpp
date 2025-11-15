class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> vec(numRows, vector<int>(numRows, -1));
        for(int i = 0; i < vec.size(); i++)
        {
            for(int j = 0; j < vec[0].size(); j++)
            {
                if(j == 0) vec[i][j] = 1;

                if(i == j) vec[i][j] = 1;
            }
        }

        for(int i = 2; i < vec.size(); i++)
        {
            for(int j = 0; j < vec[0].size(); j++)
            {
                if(i != j)
                {
                    if(j-1 >= 0 && vec[i-1][j] != -1 && vec[i-1][j-1] != -1)
                        vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
                }
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < vec.size(); i++)
        {
            vector<int> x;
            for(int j = 0; j < vec[0].size(); j++)
            {
                if(vec[i][j] != -1)
                    x.push_back(vec[i][j]);
            }
            ans.push_back(x);
            x.clear();
        }
        vec.clear();
        return ans;
    }
};