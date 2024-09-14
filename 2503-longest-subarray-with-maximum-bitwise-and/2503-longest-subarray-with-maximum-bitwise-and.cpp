class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 1, count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == maxi)
                count++;
            else
                count = 0;
            
            ans = max(ans, count);
        }
        return ans;
    }
};