class Solution {
    // Arrays to track if a number (1-9) is already used in a row, col, or 3x3 box
    bool rowCheck[9][10] = {false};
    bool colCheck[9][10] = {false};
    bool boxCheck[9][10] = {false};
    
    // Store coordinates of all empty cells to avoid re-scanning the board
    vector<pair<int, int>> emptyCells;

    bool solve(vector<vector<char>>& board, int index) 
    {
        // Base case: If we've filled all empty cells, the Sudoku is solved
        if (index == emptyCells.size())
            return true;

        int r = emptyCells[index].first;
        int c = emptyCells[index].second;
        int boxId = (r / 3) * 3 + (c / 3); // Formula to map 2D coordinates to 0-8 box index

        for (int val = 1; val <= 9; val++) 
        {
            // O(1) check to see if the number is safe to place
            if (!rowCheck[r][val] && !colCheck[c][val] && !boxCheck[boxId][val]) 
            {
                // Place the digit and update tracking arrays
                board[r][c] = val + '0';
                rowCheck[r][val] = colCheck[c][val] = boxCheck[boxId][val] = true;

                // Recurse to the next empty cell
                if (solve(board, index + 1)) {
                    return true;
                }

                // Backtrack: Remove the digit and reset tracking arrays
                board[r][c] = '.';
                rowCheck[r][val] = colCheck[c][val] = boxCheck[boxId][val] = false;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        // Step 1: Initialize tracking arrays and find all empty cells just ONCE
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                if (board[i][j] == '.') 
                    emptyCells.push_back({i, j});
                else 
                {
                    int val = board[i][j] - '0';
                    int boxId = (i / 3) * 3 + (j / 3);
                    
                    // Mark pre-existing numbers as used
                    rowCheck[i][val] = true;
                    colCheck[j][val] = true;
                    boxCheck[boxId][val] = true;
                }
            }
        }

        // Step 2: Start backtracking using the list of empty cells
        solve(board, 0);
    }
};