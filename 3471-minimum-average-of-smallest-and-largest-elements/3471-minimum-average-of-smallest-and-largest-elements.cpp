class Solution {
public:
    double minimumAverage(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        double mini = 100.00;
        int i = 0, j = nums.size()-1;
        while(i < j)
        {
            double avg = ((double)nums[i] + (double)nums[j])/2;
            mini = min(mini, avg);
            i++;
            j--;
        }
        return mini;
    }
};