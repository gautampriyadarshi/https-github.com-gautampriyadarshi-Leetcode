class Solution {
public:
    int minimumPushes(string word) 
    {
        int ans = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < word.size(); i++)
        {
            mp[word[i]]++;
        }

        vector<pair<char, int>> vec;
        for(auto x: mp)
        {
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end(), [](auto& a, auto& b)
        {
            return a.second < b.second; 
        });

        int count = 0;
        for(int i = vec.size()-1; i >= 0; i--)
        {
            count++;
            if(count <= 8)
            {
                ans = ans + 1 * vec[i].second;
            }
            else if(count > 8 && count <= 16)
            {
                ans = ans + 2 * vec[i].second;
            }
            else if(count > 16 && count <= 24)
            {
                ans = ans + 3 * vec[i].second;
            }
            else
            {
                ans = ans + 4 * vec[i].second;
            }
        }
        return ans;
    }
};