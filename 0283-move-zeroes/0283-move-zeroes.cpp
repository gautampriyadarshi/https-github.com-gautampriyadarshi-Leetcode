class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0, j = 0, n = nums.size();
        while(i < n && j < n)
        {
            if(nums[i] != 0 && nums[j] != 0)
            {
                i++;
                j++;
            }
            else if(nums[i] == 0 && nums[j] == 0)
                j++;
            else if(nums[i] == 0 && nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};