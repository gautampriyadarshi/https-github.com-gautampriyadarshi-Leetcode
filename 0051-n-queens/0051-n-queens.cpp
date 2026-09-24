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

/**************  
Time Complexity: O(N!)
In the first row, we have N choices. In the second row, we have a maximum of N-1 choices, and so on. The maximum number of nodes in the recursion tree is bounded by N!.

Because our isSafe check is now O(1), the time spent at each node is significantly reduced compared to your original O(N * N!) solution. (Note: copying the valid board to the ans array takes O(N^2) time, but the search space generation dominates the overall time).

Space Complexity: O(N)
The board takes O(N^2) space.
The three tracking vectors (cols, leftDiag, rightDiag) take O(N) space.
The recursion stack takes up to O(N) space (maximum depth of N).
(Note: This excludes the space required for the output array ans, which takes O(K * N^2) space where K is the number of valid solutions).


**************/