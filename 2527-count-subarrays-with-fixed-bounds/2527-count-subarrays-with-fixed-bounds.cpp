class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) 
    {
        int i = -1, j = 0, mn = -1, mx = -1, n = nums.size();
        long long ans = 0;

        while(j < n)
        {
            if(nums[j] < mink || nums[j] > maxk)
                i = j;

            if(mink == nums[j])
                mn = j;

            if(maxk == nums[j])
                mx = j;

            if(min(mn, mx) - i > 0) 
                ans += (min(mn, mx)-i);

            j++;
        }
        return ans;
        
    }
};