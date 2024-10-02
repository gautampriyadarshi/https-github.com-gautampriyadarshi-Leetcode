class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> help = arr;
        sort(help.begin(), help.end());
        map<int, int> mp;

        int count = 1;
        for(int i = 0; i < help.size(); i++)
        {
            if(i == 0)
                mp[help[i]] = 1;
            else if(help[i] != help[i-1])
            {
                count++;
                mp[help[i]] = count;
            }
            else
                mp[help[i]] = count;
        }

        for(int i = 0; i < arr.size(); i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};