class Solution {
    void nQueens(vector<string>& board, int row, int n, 
                 vector<vector<string>>& ans,
                 vector<bool>& cols, 
                 vector<bool>& leftDiag, 
                 vector<bool>& rightDiag) 
    {
        // Base case: All queens have been placed successfully
        if (row == n) 
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) 
        {
            // Calculate unique indices for the current cell's diagonals
            int ld = row - col + (n - 1);
            int rd = row + col;

            // O(1) Check: Is the column or either diagonal already occupied?
            if (!cols[col] && !leftDiag[ld] && !rightDiag[rd]) 
            {
                // 1. Place the queen and mark the column and diagonals as used
                board[row][col] = 'Q';
                cols[col] = true;
                leftDiag[ld] = true;
                rightDiag[rd] = true;

                // 2. Recurse to the next row
                nQueens(board, row + 1, n, ans, cols, leftDiag, rightDiag);

                // 3. Backtrack: Remove the queen and unmark for future paths
                board[row][col] = '.';
                cols[col] = false;
                leftDiag[ld] = false;
                rightDiag[rd] = false;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        // Lookup arrays to replace the O(N) isSafe function
        vector<bool> cols(n, false);
        
        // Diagonal arrays require size 2n - 1 to cover all possible diagonals
        vector<bool> leftDiag(2 * n - 1, false);
        vector<bool> rightDiag(2 * n - 1, false);
        
        nQueens(board, 0, n, ans, cols, leftDiag, rightDiag);
        return ans;
    }
};