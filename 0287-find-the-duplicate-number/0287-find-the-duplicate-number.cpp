class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int x = nums[0], ans = INT_MAX;
        
        for(int i = 1; i < nums.size(); i++)
        {
            x ^= nums[i];   // XOR of same number is 0.
            
            if(x == 0) {
                ans = nums[i];
                break;
            }
            else
                x = nums[i];
        }
        return ans;
    }
};