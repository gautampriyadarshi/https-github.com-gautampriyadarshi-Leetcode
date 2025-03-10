class Solution {
    bool isSafe(vector<vector<char>>& board, int row, int col, char value)
    {
        int n = board.size();

        for(int i = 0; i < n; i++)
        {
            if(board[row][i] == value)
                return false;

            if(board[i][col] == value)
                return false;
            
            if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == value)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        int n = board.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char value = '1'; value <= '9'; value++)
                    {
                        if(isSafe(board, i, j, value))
                        {
                            board[i][j]= value;

                            // recursive call
                            bool nextsolution = solve(board);

                            // here we are returning true because the question 
                            // clearly states that there will be only one answer.
                            if(nextsolution == true)  
                                return true;
                                
                            // backtrack
                            else    
                                board[i][j]='.';
                        }
                    }
                    // if we were not able to fill the current cell by any of digit 
                    // 1-9 that means we put wrong value in previous cell, 
                    // so returning false to go back 
                    return false;
                }
            }
        }
        // if we reach this line that means we ahve filled the sudoku correctly.
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};