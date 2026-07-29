// TC: O(NxM)
// SC: O(NxM)
class Solution {
    int Rec(int i, int j, string s1, string s2)
    {
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if (s1[i] == s2[j])
            return Rec(i - 1, j - 1, s1, s2);

        return 1 + min(Rec(i - 1, j, s1, s2), 
                    min(Rec(i, j - 1, s1, s2), Rec(i - 1, j - 1, s1, s2)));
    }

    int Mem(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1; // word1 is empty, must INSERT remaining (j+1) characters of word2
            
        if (j < 0)
            return i + 1; // word2 is empty, must DELETE remaining (i+1) characters of word1

        if (dp[i][j] != -1)
            return dp[i][j];

        // Move both pointers backward without adding to the cost.
        if (s1[i] == s2[j])
            return dp[i][j] = Mem(i - 1, j - 1, s1, s2, dp);

        // IF CHARACTERS DO NOT MATCH: Try all 3 operations and take the minimum cost.
        int deleteOp  = Mem(i - 1, j, s1, s2, dp);     // Skip s1[i], keep looking for s2[j]
        int insertOp  = Mem(i, j - 1, s1, s2, dp);     // Match s2[j] with inserted char, keep looking at s1[i]
        int replaceOp = Mem(i - 1, j - 1, s1, s2, dp); // Substitute s1[i] with s2[j], both are matched
        
        // Add 1 to the cost for performing the operation itself
        return dp[i][j] = 1 + min({deleteOp, insertOp, replaceOp});
    }
public:
    int minDistance(string str1, string str2) 
    {
        int n = str1.size(), m = str2.size();

        // Recursion:
        // return Rec(n - 1, m - 1, str1, str2);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return Mem(n - 1, m - 1, str1, str2, dp);
    }
};