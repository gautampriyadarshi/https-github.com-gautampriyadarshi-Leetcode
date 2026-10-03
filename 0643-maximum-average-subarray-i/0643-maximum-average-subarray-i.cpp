class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int maxi = INT_MIN, sum = 0;
        double ans = 0;
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        maxi = max(maxi, sum);
        ans = (double)maxi / k;

        for(int i = k; i < nums.size(); i++)
        {
            sum -= nums[i-k];
            sum += nums[i];
            maxi = max(maxi, sum);

            if(maxi == sum)
                ans = (double)maxi / k;
        }
        return ans;
    }
};