class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        
        return max(nums[0]*nums[1]*nums[n], nums[n]*nums[n-1]*nums[n-2]);
    }
};