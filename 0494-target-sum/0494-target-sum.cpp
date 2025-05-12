class Solution {
    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();

        // Space Optimization:
        vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

        if (num[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (num[0] != 0 && num[0] <= tar)
            prev[num[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= tar; sum++)
            {
                int notTake = prev[sum];
                int take = 0;

                if (num[i] <= sum)
                    take = prev[sum - num[i]];

                curr[sum] = notTake + take;
            }
            prev = curr;
        }
        return prev[tar];
    }

    int countPartition(int n, int d, vector<int> &arr)
    {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }

        if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
            return 0;

        return findWays(arr, (totalSum - d) / 2);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        // Similar to partition array into two subset with given difference.
        int n = nums.size();
        return countPartition(n, target, nums);
    }
};