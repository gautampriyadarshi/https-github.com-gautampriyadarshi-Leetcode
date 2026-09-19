class Solution {
    void solve(int ind, vector<int>& candidates, int target, vector<int> &help, 
               vector<vector<int>> &ans) 
    {
        if(ind == candidates.size())
        {
            if(target == 0)
                ans.push_back(help);
            
            return;
        }

        if(candidates[ind] <= target)
        {
            help.push_back(candidates[ind]);
            solve(ind, candidates, target - candidates[ind], help, ans);
            help.pop_back();
        }

        solve(ind+1, candidates, target, help, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> help;
        solve(0, candidates, target, help, ans);

        return ans;
    }
};