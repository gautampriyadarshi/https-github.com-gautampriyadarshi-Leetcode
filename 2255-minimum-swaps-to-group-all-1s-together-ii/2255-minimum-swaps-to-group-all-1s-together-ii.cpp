class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int total1 = 0, count1 = 0, n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                total1++;
        }

        if(total1 == 0 || total1 == nums.size())
            return 0;
        
        for(int i = 0; i < total1; i++)
        {
            if(nums[i] == 1)
                count1++;
        }

        int maxi = count1;
        for(int i = 0; i < n; i++)
        {
            count1 -= nums[i];
            count1 += nums[(i + total1) % n];
            maxi = max(maxi, count1);
        }
        return total1 - maxi;
    }
};