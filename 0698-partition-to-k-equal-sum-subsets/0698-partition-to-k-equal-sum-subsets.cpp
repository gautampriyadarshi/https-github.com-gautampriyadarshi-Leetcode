class Solution {
    // DP + Bitmasking parameters:
    // mask: an integer acting as our 'visited' array (bits 0 or 1)
    // currentSum: the sum of the current subset we are building
    // dp: our memoization table storing the result of a specific mask
    bool memoize(int mask, int currentSum, int target, vector<int>& nums, vector<int>& dp) 
    {
        // Base Case: If the mask has all bits set to 1 (all elements used)
        // For n=3, (1<<3)-1 is 8-1 = 7 (binary 111)
        if (mask == (1 << nums.size()) - 1)
            return true;
        
        // DP Check: If we have already visited this exact combination of used elements
        if (dp[mask] != -1)
            return dp[mask];
        
        for (int i = 0; i < nums.size(); i++) 
        {
            // Check if the i-th bit is 0 (meaning the element is NOT used yet)
            if ((mask & (1 << i)) == 0) 
            {
                if (currentSum + nums[i] <= target) 
                {
                    // If adding this element hits the target, nextSum wraps around to 0
                    // to start building the next subset!
                    int nextSum = (currentSum + nums[i]) % target;
                    
                    // Mark the i-th element as used by setting its bit to 1 using OR (|)
                    if (memoize(mask | (1 << i), nextSum, target, nums, dp))
                        return dp[mask] = 1;
                }
            }
        }
        
        // Cache the failure for this state
        return dp[mask] = 0;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % k != 0)
            return false;
            
        int target = sum / k;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        if (nums[0] > target)
            return false;
        
        int n = nums.size();
        
        // DP TABLE SETUP:
        // There are 2^n possible combinations of used/unused elements.
        // (1 << n) is a bitwise left-shift that perfectly calculates 2^n.
        vector<int> dp(1 << n, -1);
        
        // Start with a mask of 0 (no elements used)
        return memoize(0, 0, target, nums, dp);
    }
};