class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int x = -1, y = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        return {x,y};
    }
};