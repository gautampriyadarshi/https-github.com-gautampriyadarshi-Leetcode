/* Giving correct output of all cases but memory limit exceeded:
class Solution {
    bool totalSum(vector<int> &subset, int target)
    {
        int x = 0;
        for(int i = 0; i < subset.size(); i++)
        {
            x += subset[i];
        }
        
        if(x == target)
            return true;
        
        return false;
    }
    void findSubset(int i, int target, set<vector<int>> &st, vector<int>& candidates, vector<int> subset)
    {
        if(i == candidates.size())
        {
            if(totalSum(subset, target))
            {
                sort(subset.begin(), subset.end());
                st.insert(subset);
            }
            return;
        }
        
        subset.push_back(candidates[i]);
        findSubset(i+1, target, st, candidates, subset);
        subset.pop_back();
        findSubset(i+1, target, st, candidates, subset);
    }   
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int> subset;
        set<vector<int>> st;
        findSubset(0, target, st, candidates, subset);

        vector<vector<int>> ans;
        for(auto x: st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};  */

class Solution {
    void backtrack(vector<int> &candidates, vector<int> &output,vector<vector<int>> &ans ,int index, int target)
    {
        if(target == 0)
        {
            ans.push_back(output) ;
            return;
        }

        if(target < 0 || index >= candidates.size())
            return;

        for(int i = index ; i < candidates.size() ; i++)
        {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            
            output.push_back(candidates[i]);
            backtrack(candidates, output, ans, i+1, target-candidates[i]);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans ;
        vector<int>output ;
        int index = 0 ;
        backtrack(candidates, output, ans, index, target);
        return ans ;
    }
};