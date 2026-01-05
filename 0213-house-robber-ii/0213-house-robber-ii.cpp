class Solution {
    int Rec(int ind, vector<int> &nums)
    {
        if (ind == 0)
            return nums[ind]; // ind is 0 means ind+1 was not picked and ind+2 was picked.

        if (ind < 0)
            return 0;

        // Adjacent elements need to be skipped thats's why we did (ind - 2);
        int pick = nums[ind] + Rec(ind - 2, nums);
        int notPick = 0 + Rec(ind - 1, nums);

        return max(pick, notPick);
    }

    int Mem(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind == 0)
            return nums[ind];

        if (ind < 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + Mem(ind - 2, nums, dp);
        int notPick = 0 + Mem(ind - 1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

    int maximumNonAdjacentSum(vector<int> &vec)
    {
        int n = vec.size();
        // Space Optimization:

        int prev = vec[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = vec[i];

            if (i > 1)
                take += prev2;

            int notTake = 0 + prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            // temp1 don't contain first element and temp2 don't contain last element.
            if (i != 0)
                temp1.push_back(nums[i]);

            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        int t1 = temp1.size(), t2 = temp2.size();

        // Recursion:
        // return max(Rec(t1 - 1, temp1), Rec(t2 - 1, temp2));

        // Memoization:
        vector<int> dp1(t1, -1), dp2(t2, -1);
        return max(Mem(t1 - 1, temp1, dp1), Mem(t2 - 1, temp2, dp2));

        // return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
};