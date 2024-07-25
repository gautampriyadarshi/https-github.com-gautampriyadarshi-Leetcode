class Solution {
public:
    int maximumTop(vector<int>& nums, int k) 
    {
        // 184/197 cases passed:
    /*  int maxi = INT_MIN;
        if(k == 2)
            return nums[0];

        if(nums.size() == 1)
            return -1;
        
        if(k > nums.size())
        {
            for(int i = 0; i < nums.size(); i++)
            {
                maxi = max(maxi, nums[i]);
            }
        }
        else
        {
            for(int i = 0; i <= k; i++)
            {
                maxi = max(maxi, nums[i]);
            }
        }
        return maxi;    */

        int i, m=-1;
        for(i=0; i<nums.size()-1; i++)
        {
            if(k==0)
                break;
            if(k==1)
            {
                m=max(m, nums[i+1]);
                break;
            }
            m = max(m, nums[i]);
            k--;
        }
        if(k>1 && m!=-1)
            m=max(m, nums[i]);
        else if(m==-1 && k%2==0)
            m = nums[0];
        return m;
    }
};