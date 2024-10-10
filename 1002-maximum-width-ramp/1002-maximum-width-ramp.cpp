class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        // TLE: 94/101 cases passed.
        /*  int maxi = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] >= nums[i])
                    maxi = max(maxi, j - i);
            }
        }
        return maxi;    */
        
        stack<int> s;   
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (s.empty() || nums[s.top()] > nums[i]) 
                s.push(i);
        }
        
        int maxWidth = 0;
        for (int j = nums.size() - 1; j >= 0; --j) 
        {
            while (!s.empty() && nums[s.top()] <= nums[j]) 
            {
                maxWidth = max(maxWidth, j - s.top());
                s.pop();
            }
        }
        return maxWidth;
    }
};