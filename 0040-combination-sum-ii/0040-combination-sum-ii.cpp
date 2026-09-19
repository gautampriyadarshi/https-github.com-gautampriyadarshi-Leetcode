class Solution {
    void solve(int ind, vector<int>& candidates, int target, vector<int>& help, vector<vector<int>>& ans) 
    {
        if (target == 0) 
        {
            ans.push_back(help);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) 
        {
            // Skip duplicates at the same level of the recursion tree
            if (i > ind && candidates[i] == candidates[i - 1]) 
                continue;
            
            // Optimization: Since array is sorted, if current element exceeds target, further elements will too
            if (candidates[i] > target) 
                break;

            help.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], help, ans);
            help.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> help;
        solve(0, candidates, target, help, ans);

        return ans;
    }
};