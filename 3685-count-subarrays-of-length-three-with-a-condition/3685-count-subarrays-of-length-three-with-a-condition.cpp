class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int count = 0;
        for(int i = 1; i < nums.size()-1; i++)
        {
            double frac = (double)nums[i]/2;
            if(frac == (double)(nums[i-1] + nums[i+1]))
                count++;
        }
        return count;
    }
};