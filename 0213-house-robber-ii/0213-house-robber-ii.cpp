class Solution {
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

        return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
};