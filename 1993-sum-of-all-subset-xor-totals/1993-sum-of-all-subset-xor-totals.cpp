class Solution {
    void getSubset(vector<int> nums,  vector<int> output, int index, vector<vector<int>>& ans)
    {
        if(index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        getSubset(nums, output, index + 1, ans);
        
        int element = nums[index];
        output.push_back(element);
        getSubset(nums, output, index + 1, ans);
    }
public:
    int subsetXORSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0, sum = 0;
        getSubset(nums, output, index, ans);

        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i].size() == 1)
                sum += ans[i][0];
            else 
            {
                int val = ans[i][0];
                for(int j = 1; j < ans[i].size(); j++)
                {
                    int x = val ^ ans[i][j];
                    val = x;
                }
                sum += val;
            }
        }
        return sum;
    }
};