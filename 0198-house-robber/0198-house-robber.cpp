class Solution {
    int Rec(int ind, vector<int>& nums)
    {
        if(ind == 0)
            return nums[0];
        
        if(ind < 0)
            return 0;
        
        int pick = nums[ind] + Rec(ind - 2, nums);
        int notPick = 0 + Rec(ind - 1, nums);

        return max(pick, notPick);
    }

    int Mem(int ind, vector<int>& nums, vector<int> &dp)
    {
        if(ind == 0)
            return nums[0];
        
        if(ind < 0)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];
        
        int pick = nums[ind] + Mem(ind - 2, nums, dp);
        int notPick = 0 + Mem(ind - 1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        // Recursion:
        // return Rec(n - 1, nums);

        // Memoization:
        vector<int> dp(n, -1);
        return Mem(n - 1, nums, dp);
    }
};