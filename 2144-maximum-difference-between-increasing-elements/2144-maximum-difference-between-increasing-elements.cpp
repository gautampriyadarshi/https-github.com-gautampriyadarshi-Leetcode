class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        long long maxi = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] > nums[i])
                {
                    long long diff = nums[j] - nums[i];
                    maxi = max(maxi, diff);
                }
            }
        }
        return maxi;
    }
};