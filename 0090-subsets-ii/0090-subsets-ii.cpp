class Solution {
    void findSubset(int i, vector<int>& nums, vector<int> subset, set<vector<int>> &st)
    {
        if(i == nums.size())
        {
            sort(subset.begin(), subset.end());
            st.insert(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        findSubset(i+1, nums, subset, st);
        subset.pop_back();
        findSubset(i+1, nums, subset, st);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> subset;
        set<vector<int>> st;
        findSubset(0, nums, subset, st);

        vector<vector<int>> vec;
        for(auto x: st)
        {
            vec.push_back(x);
        }
        return vec;
    }
};