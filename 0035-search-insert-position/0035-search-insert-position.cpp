class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int ans = 0, j = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == target)
                return i;

            if(nums[i] < target)
                j++;
            else if(nums[i] > target)
                return j;
            
            if(target > nums[n-1])
                return n;
        }
        return ans;
    }
};