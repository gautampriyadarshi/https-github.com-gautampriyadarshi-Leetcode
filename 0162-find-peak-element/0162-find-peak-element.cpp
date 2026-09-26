class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int maxi = INT_MIN, index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                index = i;
            }
        }   
        return index;
    }
};