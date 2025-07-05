class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        int maxi = -1;
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }

        for(auto x: mp)
        {
            if(x.second == x.first)
                maxi = max(maxi, x.first);
        }
        return maxi;
    }
};