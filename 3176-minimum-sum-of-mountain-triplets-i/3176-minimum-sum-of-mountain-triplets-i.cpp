class Solution {
public:
    int minimumSum(vector<int>& nums) 
    {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size()-2; i++)
        {
            for(int j = i+1; j < nums.size()-1; j++)
            {
                for(int k = j+1; k < nums.size(); k++)
                {
                    if(nums[j] > nums[i] && nums[j] > nums[k])
                    {
                        int sum = nums[i] + nums[j] + nums[k];
                        mini = min(mini, sum);
                    }
                }
            }
        }   

        if(mini == INT_MAX)
            return -1;
        
        return mini;
    }
};

