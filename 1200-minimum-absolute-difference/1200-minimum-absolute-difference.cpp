class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;

        for(int i = 0; i < arr.size()-1; i++)
        {
            int x = arr[i], y = arr[i+1];
            int diff = abs(x-y);
            mini = min(mini, diff);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < arr.size()-1; i++)
        {
            int x = arr[i], y = arr[i+1];
            int diff = abs(x-y);

            if(diff == mini)
                ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
    }
};