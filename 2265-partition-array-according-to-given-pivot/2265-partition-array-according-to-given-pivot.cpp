class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int count = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == pivot)
                count++;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivot)
                ans.push_back(nums[i]);
        }

        while(count > 0)
        {
            ans.push_back(pivot);
            count--;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > pivot)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};