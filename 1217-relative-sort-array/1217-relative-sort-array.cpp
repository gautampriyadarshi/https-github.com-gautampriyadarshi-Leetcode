class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map<int,int> mp1;
        unordered_map<int, bool> mp2;

        for(int i = 0; i < arr1.size(); i++)
        {
            mp1[arr1[i]]++;
        }

        vector<int> ans, help;
        for(int i = 0; i < arr2.size(); i++)
        {
            mp2[arr2[i]] = true;
            while(mp1[arr2[i]] > 0)
            {
                ans.push_back(arr2[i]);
                mp1[arr2[i]]--;
            }
        }

        for(int i = 0; i < arr1.size(); i++)
        {
            if(mp2[arr1[i]] == false)
                help.push_back(arr1[i]);
        }

        if(help.size() > 0)
        {
            sort(help.begin(), help.end());
            for(int i = 0; i < help.size(); i++)
            {
                ans.push_back(help[i]);
            }
        }
        return ans;
    }
};