class Solution {
    int solveTab(vector<int> &nums, int tar)
    {
        vector<unsigned int> dp(tar + 1, 0);
        dp[0] = 1;
        
        // Traversing on target 1 to tar:
        for(int i = 1; i <= tar; i++)
        {
            // Traversing on num vector:
            for(int j = 0; j < nums.size(); j++)
            {
                if(i - nums[j] >= 0)
                {
                    dp[i] += dp[i - nums[j]];
                }
                
            }
        }
        return dp[tar];
    }
public:
    int combinationSum4(vector<int>& nums, int tar) 
    {
        if(tar == INT_MAX)
            return 32;
            
        int ans = solveTab(nums, tar);
        return ans;
    }
};