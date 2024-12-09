class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<int> arr(n, n);
        vector<bool> ans;

        for(int i = n-2; i >= 0; i--)
        {
            if((nums[i] + nums[i+1]) & 1) 
                arr[i] = arr[i+1];
            else 
                arr[i] = i;
        }
        
        for(auto it : queries)
        {
            if(arr[it[0]] < it[1]) 
                ans.push_back(false);
            else 
                ans.push_back(true);
        }
        return ans;
    }
};