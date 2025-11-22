class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size(), x = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 3 == 0)
                x++;
        }
        return n-x;
    }
};