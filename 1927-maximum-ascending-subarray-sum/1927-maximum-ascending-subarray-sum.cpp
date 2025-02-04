class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];

        int maxi = 0;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            maxi = max(maxi, sum);
            if(nums[i] > nums[i-1])
            {
                sum += nums[i];
                maxi = max(maxi, sum);
            }
            else
                sum = nums[i];
        }
        return maxi;
    }
};