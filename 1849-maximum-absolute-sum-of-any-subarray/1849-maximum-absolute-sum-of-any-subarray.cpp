class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int maxi = 0, sum = 0, mini;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if(sum > maxi)
                maxi = sum;
            
            if(sum < mini)
                mini = sum;
        }
        return abs(maxi - mini);
    }
};