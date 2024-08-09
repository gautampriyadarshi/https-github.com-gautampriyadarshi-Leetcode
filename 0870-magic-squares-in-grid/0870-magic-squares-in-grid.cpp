class Solution {
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        vector<int> count(10, 0);
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                int num = grid[i + x][j + y];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }

        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        
        for(int x = 0; x < 3; ++x) {
            if(sum != (grid[i + x][j] + grid[i + x][j + 1] + grid[i + x][j + 2])) return false;
        }
        
        for(int y = 0; y < 3; ++y) {
            if(sum != (grid[i][j + y] + grid[i + 1][j + y] + grid[i + 2][j + y])) return false;
        }
        
        if(sum != (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2])) return false;
        if(sum != (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2])) return false;

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        /* Some cases not passed due to little bug:
        if(grid.size() <= 2 || grid[0].size() <= 2)
            return 0;

        int count = 0;
        for(int i = 0; i < grid.size()-2; i++)
        {
            for(int j = 0; j < grid[0].size()-2; j++)
            {
                int row = i, col = j;
                unordered_map<int, bool> mp;
                bool first = true, second = false;
                while(row < i+3 && col < j+3)
                {
                    if(grid[row][col] == true)
                    {
                        first = false;
                        break;
                    }
                    else
                        mp[grid[row][col]] = true;
                    
                    row++;
                    col++;
                }

                row = i, col = j;
                int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
                int diag2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];

                int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
                int row2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
                int row3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];

                int col1 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
                int col2 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
                int col3 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];

                if(diag1 == diag2 && row1 == row2 && row1 == row3 && col1 == col2 && col1 == col3 && diag1 == row1 && diag1 == col1){
                    second = true;
                }

                cout << first << " " << second;

                if(first == true && second == true)
                    count++;
            }
        }
        return count;   */

        int cnt = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        if(row < 3 || col < 3) return 0;

        for(int i = 0; i <= row - 3; ++i) {
            for(int j = 0; j <= col - 3; ++j) {
                if(isValid(i, j, grid)) cnt++;
            }
        }
        return cnt;
    }
};