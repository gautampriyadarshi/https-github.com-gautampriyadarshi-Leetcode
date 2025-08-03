class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int m = -1, n = -1;
        for(int i = 1; i < nums.size()-1; i++)
        {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                m = i;
            else if(nums[i] < nums[i-1] && nums[i] < nums[i+1])
                n = i;
        }

        if(m == -1 || n == -1)
            return false;

        for(int i = 1; i < nums.size(); i++)
        {
            if(i <= m)
            {
                if(nums[i] <= nums[i-1])
                    return false;
            }
            else if(i > m && i <= n)
            {
                if(nums[i] >= nums[i-1])
                    return false;
            }
            else if(i > n)
            {
                if(nums[i] <= nums[i-1])
                    return false;
            }
        }
        return true;
    }
};