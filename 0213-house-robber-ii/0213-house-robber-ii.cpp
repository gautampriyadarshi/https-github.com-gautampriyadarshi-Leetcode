class Solution {
    int Rec(int ind, vector<int>& temp)
    {
        if(ind == 0)
            return temp[0];
        
        if(ind < 0)
            return 0;
        
        int pick = temp[ind] + Rec(ind - 2, temp);
        int notPick = 0 + Rec(ind - 1, temp);

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
        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0) // temp1 don't contain first element.
                temp1.push_back(nums[i]);

            if (i != n - 1) // temp2 don't contain last element.
                temp2.push_back(nums[i]);
        }

        int t1 = temp1.size(), t2 = temp2.size();

        // Recursion:
        // return max(Rec(t1 - 1, temp1), Rec(t2 - 1, temp2));

        // Memoization:
        vector<int> dp1(t1, -1), dp2(t2, -1);
        return max(Mem(t1 - 1, temp1, dp1), Mem(t2 - 1, temp2, dp2));
    }
};