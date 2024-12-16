class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> help = nums;
        sort(help.begin(), help.end());
        int count = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < help.size(); j++)
            {
                if(nums[i] > help[j])
                    count++;
                else if(nums[i] == help[j])
                {
                    ans.push_back(count);
                    break;
                }
            }
            count = 0;
        }
        return ans;
    }
};