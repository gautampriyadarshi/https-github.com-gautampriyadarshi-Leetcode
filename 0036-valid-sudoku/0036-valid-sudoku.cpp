class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) 
    {
        // Row:
        for(int i = 0; i < 9; i++)
        {
            unordered_map<char, bool>mp;
            for(int j = 0; j < 9; j++)
            {
                if(mp[mat[i][j]] == true)
                    return false;

                if(mat[i][j] != '.')
                    mp[mat[i][j]] = true;
            }
        }

        // Column:
        for(int j = 0; j < 9; j++)
        {
            unordered_map<char, bool>mp;
            for(int i = 0; i < 9; i++)
            {
                if(mp[mat[i][j]] == true)
                    return false;

                if(mat[i][j] != '.')
                    mp[mat[i][j]] = true;
            }
        }

        // Small box: 3*3
        vector<unordered_map<char,int>>box(9);
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                if(mat[i][j]!='.')
                {
                   box[((i/3)*3+j/3)][mat[i][j]]++;

                   if(box[((i/3)*3+j/3)][mat[i][j]]>1)
                       return false;
                   
               } 
            }
        }
        return true;
    }
};