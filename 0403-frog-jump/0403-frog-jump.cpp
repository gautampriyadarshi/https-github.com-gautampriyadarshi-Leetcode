// ind: current stone index
// k: the distance of the jump we just made to get here
class Solution {
    bool Rec(int ind, int k, vector<int>& stones) 
    {
        if (ind == stones.size() - 1)
            return true;
        
        for (int nextInd = ind + 1; nextInd < stones.size(); nextInd++) 
        {
            int jumpDistance = stones[nextInd] - stones[ind];
            
            // If the jump is too small, we just skip it 
            if (jumpDistance < k - 1)
                continue;
            
            // If the jump is too large, we can stop checking!
            if (jumpDistance > k + 1)
                break;
            
            // If the jump distance is exactly k-1, k, or k+1, it's a valid move.
            if (Rec(nextInd, jumpDistance, stones))
                return true;
        }
        return false;
    }

    bool Mem(int ind, int k, vector<int>& stones, vector<vector<int>> &dp) 
    {
        if (ind == stones.size() - 1)
            return true;
        
        if(dp[ind][k] != -1)
            return dp[ind][k];
        
        for (int nextInd = ind + 1; nextInd < stones.size(); nextInd++) 
        {
            int jumpDistance = stones[nextInd] - stones[ind];
            
            // If the jump is too small, we just skip it 
            if (jumpDistance < k - 1)
                continue;
            
            // If the jump is too large, we can stop checking!
            if (jumpDistance > k + 1)
                break;
            
            // If the jump distance is exactly k-1, k, or k+1, it's a valid move.
            if (Mem(nextInd, jumpDistance, stones, dp))
                return dp[nextInd][k] = 1;
        }
        return dp[ind][k] = 0;
    }
public:
    bool canCross(vector<int>& stones) 
    {
        if(stones[1] != 1)
            return false;
        
        // Recursion:
        // return Rec(1, 1, stones);

        // Memoization:
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return Mem(1, 1, stones, dp);
    }
};