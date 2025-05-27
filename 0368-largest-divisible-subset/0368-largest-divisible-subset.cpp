class Solution {
    vector<int> optimizedTab(vector<int>& nums)
    {
        // Same code as Longest Increasing Subsequence with a condition changed.
        
        int n = nums.size(), maxi = 1, lastIndex = 0;
        vector<int> dp(n, 1), hash(n);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());

        return temp;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        return optimizedTab(nums);
    }
};