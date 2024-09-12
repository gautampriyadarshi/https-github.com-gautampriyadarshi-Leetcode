class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int count = 0;
        unordered_map<char,int> mp;
        for(int i = 0; i < allowed.size(); i++)
        {
            mp[allowed[i]]++;
        }

        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(mp[words[i][j]] == 0)
                {
                    count++;
                    break;
                }
            }
        }
        return words.size() - count;
    }
};