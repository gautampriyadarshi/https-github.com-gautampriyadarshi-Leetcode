class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
            
        int ans = -1;
        for(int i = 1; i < nums.size()-1; i++)
        {
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
            {
                ans = nums[i];
                break;
            }
        }

        if(ans == -1)
        {
            if(nums[0] != nums[1])
                ans = nums[0];
            else
                ans = nums[nums.size()-1];
        }
        return ans;
    }
};