class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int, int> mp, mp2;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }

        for(auto x: mp)
        {
            if(mp2[x.second] > 0)
                return false;

            mp2[x.second]++;
        }

        mp.clear();
        mp2.clear();

        return true;
    }
};