class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_map<int, int> mp1, mp2;

        for(int row = 0; row < matrix.size(); row++)
        {
            for(int col = 0; col < matrix[0].size(); col++)
            {
                if(matrix[row][col] == 0)
                {
                    mp1[row]++;
                    mp2[col]++;
                }
            }
        }

        for(auto row: mp1)
        {
            for(int col = 0; col < matrix[0].size(); col++)
            {
                matrix[row.first][col] = 0;
            }
        }

        for(auto col: mp2)
        {
            for(int row = 0; row < matrix.size(); row++)
            {
                matrix[row][col.first] = 0;
            }
        }
    }
};