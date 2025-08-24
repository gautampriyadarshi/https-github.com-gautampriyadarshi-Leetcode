class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        int maxi = 0;

        int i = 0, j = 0, count0 = 0, total = 0;
        while(j < n)
        {
            if(nums[j] == 0)
            {
                count0++;
                while(count0 > 1)
                {
                    if(nums[i] == 0)
                        count0--;
                    else
                        total--;
                    i++;
                }
            }
            else
            {
                total++;
                maxi = max(maxi, total);
            }
            j++;
        }

        if(maxi == nums.size())
            return --maxi;

        return maxi;
    }
};