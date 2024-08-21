class Solution {
    int solveMem(int i, int j, const string& s, vector<vector<int>>& dp) 
    {
        if (i > j) 
            return 0;
        
        if (dp[i][j] != -1) 
            return dp[i][j];

        char firstLetter = s[i];

        // If the current character is not repeated in the rest of the string
        int answer = 1 + solveMem(i + 1, j, s, dp);

        for (int k = i + 1; k <= j; k++) 
        {
            // If repeated then update the answer
            if (s[k] == firstLetter) 
            {
                // Splitting from i -> k - 1 (remove the last character)
                // and from k + 1 -> j  
                           
                int betterAnswer = solveMem(i, k - 1, s, dp) + solveMem(k + 1, j, s, dp);
                answer = min(answer, betterAnswer);
            }
        }
        return dp[i][j] = answer;
    }
public:
    int strangePrinter(string s) 
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solveMem(0, n - 1, s, dp);
    }
};