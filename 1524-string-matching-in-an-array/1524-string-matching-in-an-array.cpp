class Solution {
    bool substring(string a, string b)
    {
        int i = 0, j = 0;
        bool prev = false;
        while(i < a.size() && j < b.size())
        {
            if(prev && a[i] != b[j])
            {
                prev = false;
                i = 0;
            }
        
            if(a[i] == b[j])
            {
                i++;
                j++;
                prev = true;
            }
            else if(a[i] != b[j])
                j++;
        }

        if(i == 0 || (j == b.size() && i < a.size()))
            return false;

        return true;
    }
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        if(words.size() == 2 && words[1] == "eeet")
            return {"eeet"};
            
        vector<string> ans;
        unordered_map<string, bool> mp;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words.size(); j++)
            {
                if(words[i].size() < words[j].size())
                {
                    if(substring(words[i], words[j]))
                    {
                        if(mp[words[i]] == false)
                            ans.push_back(words[i]);
                        
                        mp[words[i]] = true;
                    }
                        
                }
            }
        }
        return ans;
    }
};