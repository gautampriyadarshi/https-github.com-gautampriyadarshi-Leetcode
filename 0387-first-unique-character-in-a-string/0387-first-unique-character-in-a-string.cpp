class Solution {
public:
    int firstUniqChar(string s) 
    {
        int index = -1;
        map<char,int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]] == 1)
            {
                index = i;
                break;
            }
        }
        return index;
    }
};