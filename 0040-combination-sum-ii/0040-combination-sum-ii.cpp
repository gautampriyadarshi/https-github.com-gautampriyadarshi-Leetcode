class Solution {
    void combinations (vector<int> &ds, int index, int target, vector<vector<int>> &ans, vector<int> &candidates) 
    {
        if (target==0) 
        {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) 
        {
            if (candidates[i] > target) 
                break;

            if (i >= 1 && i > index && candidates[i] == candidates[i-1]) 
                continue;

            ds.push_back(candidates[i]);
            combinations(ds, i+1, target-candidates[i], ans, candidates);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> ds = {};
        sort(candidates.begin(), candidates.end());
        combinations(ds, 0, target, ans, candidates);
        return ans;
    }
};